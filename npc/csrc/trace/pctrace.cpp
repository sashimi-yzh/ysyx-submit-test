#include "include/common.h"
#include <cstdio>
#include <cstdint>
#include <string>


static std::string pctrace_path() {
    if (!build_dir.empty() && build_dir.back() == '/')
        return build_dir + "pctrace.pct.bz2";
    return build_dir + "/pctrace.pct.bz2";
}

static std::string pctrace_read_path() {
    if (!build_dir.empty() && build_dir.back() == '/')
        return build_dir + "../resource/pctrace.pct.bz2";
    return build_dir + "/../resource/pctrace.pct.bz2";
}

/* ============================ 记录 ============================ */
namespace {
FILE     *w_fp = nullptr;
bool      w_started = false;
uint32_t  w_prev_pc = 0;
int32_t   w_cur_delta = 0;
uint64_t  w_cur_run = 0;

uint8_t   w_buf[1 << 16];
size_t    w_buf_len = 0;

void w_flush_buf() {
    if (w_buf_len) { fwrite(w_buf, 1, w_buf_len, w_fp); w_buf_len = 0; }
}
inline void w_byte(uint8_t b) {
    if (w_buf_len == sizeof(w_buf)) w_flush_buf();
    w_buf[w_buf_len++] = b;
}
void w_uvarint(uint64_t v) {
    while (v >= 0x80) { w_byte((uint8_t)(v | 0x80)); v >>= 7; }
    w_byte((uint8_t)v);
}
void w_svarint(int32_t s) {
    uint32_t zz = ((uint32_t)s << 1) ^ (uint32_t)(s >> 31);   // zigzag
    w_uvarint(zz);
}
void w_flush_token() {
    if (w_cur_run) {
        w_uvarint(w_cur_run);
        w_svarint(w_cur_delta);
        w_cur_run = 0;
    }
}
} // namespace

bool pctrace_write_init() {
    std::string cmd = "bzip2 -c > '" + pctrace_path() + "'";
    w_fp = popen(cmd.c_str(), "w");
    w_started = false;
    w_buf_len = 0;
    w_cur_run = 0;
    return w_fp != nullptr;
}

void pctrace_write_record(uint32_t pc) {
    if (!w_fp) return;
    if (!w_started) {
        // magic "PCT1" + 首条绝对 PC(小端)
        w_byte('P'); w_byte('C'); w_byte('T'); w_byte('1');
        w_byte((uint8_t)pc); w_byte((uint8_t)(pc >> 8));
        w_byte((uint8_t)(pc >> 16)); w_byte((uint8_t)(pc >> 24));
        w_prev_pc = pc;
        w_started = true;
        return;
    }
    int32_t delta = (int32_t)(pc - w_prev_pc);
    if (w_cur_run && delta == w_cur_delta) {
        w_cur_run++;                 // 延续当前游程(典型情况:顺序执行,delta==4)
    } else {
        w_flush_token();             // 跳转/分支:结束上一个游程
        w_cur_delta = delta;
        w_cur_run = 1;
    }
    w_prev_pc = pc;
}

bool pctrace_write_close() {
    if (!w_fp) return false;
    if (w_started) w_flush_token();
    w_flush_buf();
    int rc = pclose(w_fp);
    w_fp = nullptr;
    return rc == 0;
}

/* ============================ 回放 ============================ */
namespace {
FILE     *r_fp = nullptr;
uint8_t   r_buf[1 << 16];
size_t    r_buf_len = 0, r_buf_pos = 0;
bool      r_eof = false;
bool      r_header_done = false;
uint32_t  r_pc = 0;
uint64_t  r_run_remain = 0;
int32_t   r_cur_delta = 0;

int r_byte() {
    if (r_buf_pos == r_buf_len) {
        if (r_eof) return -1;
        size_t got = fread(r_buf, 1, sizeof(r_buf), r_fp);
        if (got == 0) { r_eof = true; return -1; }
        r_buf_len = got; r_buf_pos = 0;
    }
    return r_buf[r_buf_pos++];
}
bool r_uvarint(uint64_t *out) {
    uint64_t v = 0; int shift = 0, c;
    for (;;) {
        c = r_byte();
        if (c < 0) return false;
        v |= (uint64_t)(c & 0x7f) << shift;
        if (!(c & 0x80)) break;
        shift += 7;
        if (shift >= 64) return false;     // 损坏
    }
    *out = v; return true;
}
bool r_svarint(int32_t *out) {
    uint64_t zz;
    if (!r_uvarint(&zz)) return false;
    uint32_t u = (uint32_t)zz;
    *out = (int32_t)((u >> 1) ^ (0u - (u & 1)));   // zigzag 解码
    return true;
}
} // namespace

bool pctrace_read_init() {
    std::string cmd = "bzcat '" + pctrace_read_path() + "'";
    r_fp = popen(cmd.c_str(), "r");
    r_buf_len = r_buf_pos = 0;
    r_eof = false;
    r_header_done = false;
    r_run_remain = 0;
    return r_fp != nullptr;
}

bool pctrace_read_next(uint32_t *pc) {
    if (!r_fp) return false;
    if (!r_header_done) {
        int m0 = r_byte(), m1 = r_byte(), m2 = r_byte(), m3 = r_byte();
        if (m0 < 0) return false;                          // 空文件
        if (m0 != 'P' || m1 != 'C' || m2 != 'T' || m3 != '1') return false;
        int b0 = r_byte(), b1 = r_byte(), b2 = r_byte(), b3 = r_byte();
        if (b0 < 0 || b1 < 0 || b2 < 0 || b3 < 0) return false;
        r_pc = (uint32_t)b0 | ((uint32_t)b1 << 8)
             | ((uint32_t)b2 << 16) | ((uint32_t)b3 << 24);
        r_header_done = true;
        *pc = r_pc;
        return true;                                       // 发出首条绝对 PC
    }
    if (r_run_remain == 0) {
        uint64_t cnt;
        if (!r_uvarint(&cnt)) return false;                // 干净 EOF
        int32_t d;
        if (!r_svarint(&d)) return false;                  // 截断/损坏
        if (cnt == 0) return false;                        // 损坏:游程必 >=1
        r_run_remain = cnt;
        r_cur_delta = d;
    }
    r_pc = (uint32_t)(r_pc + (uint32_t)r_cur_delta);
    r_run_remain--;
    *pc = r_pc;
    return true;
}

bool pctrace_read_close() {
    if (!r_fp) return false;
    int rc = pclose(r_fp);
    r_fp = nullptr;
    return rc == 0;
}