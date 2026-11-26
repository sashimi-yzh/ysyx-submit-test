#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

#define WIDTH 400
#define HEIGHT 300
#define STEPS 100  // 每轮渐变的步数
#define NORMAL_DELAY 50  // 正常渐变延迟（毫秒）
#define FAST_DELAY 10    // 加速渐变延迟（毫秒）

// 目标颜色数组
static uint32_t target_colors[] = {
    0x000000, 0xff0000, 0x00ff00, 0x0000ff,
    0xffff00, 0xff00ff, 0x00ffff, 0xffffff
};

// 提取RGB分量
static inline uint8_t get_r(uint32_t color) { return (color >> 16) & 0xff; }
static inline uint8_t get_g(uint32_t color) { return (color >> 8) & 0xff; }
static inline uint8_t get_b(uint32_t color) { return color & 0xff; }

// 合成RGB颜色
static inline uint32_t make_color(uint8_t r, uint8_t g, uint8_t b) {
    return (r << 16) | (g << 8) | b;
}

// 填充整个屏幕为指定颜色
void draw(uint32_t color) {
    static uint32_t color_buf[WIDTH * HEIGHT];
    
    // 填充颜色缓冲区
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        color_buf[i] = color;
    }
    
    // 一次性绘制整个屏幕
    io_write(AM_GPU_FBDRAW, 0, 0, color_buf, WIDTH, HEIGHT, true);
}

// 检查按键状态
// 返回值: 0=无按键, 1=ESC键, 2=其他键按下
int check_key() {
    AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
    
    if (ev.keycode == AM_KEY_NONE) {
        return 0;  // 无按键
    }
    
    if (ev.keycode == AM_KEY_ESCAPE && ev.keydown) {
        return 1;  // ESC键按下
    }
    
    if (ev.keydown) {
        return 2;  // 其他键按下
    }
    
    return 0;
}

// 简单的随机数生成器
static unsigned int seed = 12345;
int simple_rand() {
    seed = seed * 1103515245 + 12345;
    return (seed / 65536) % 32768;
}

int main() {
    ioe_init(); // 初始化GUI
    
    uint32_t current_color = 0x000000;  // 当前颜色（黑色）
    int target_index = 0;  // 目标颜色索引
    int step = 0;  // 当前渐变步数
    unsigned long last_time = 0;
    int delay = NORMAL_DELAY;  // 当前延迟时间
    int key_pressed = 0;  // 记录是否有非ESC键按下
    
    // 初始化随机种子
    seed = io_read(AM_TIMER_UPTIME).us;
    
    printf("屏保程序启动...\n");
    printf("按ESC退出，按其他键加速渐变\n");
    
    while (1) {
        unsigned long current_time = io_read(AM_TIMER_UPTIME).us / 1000;  // 转换为毫秒
        
        // 检查按键
        int key_status = check_key();
        if (key_status == 1) {
            printf("检测到ESC键，退出程序\n");
            break;  // ESC键退出
        } else if (key_status == 2) {
            delay = FAST_DELAY;  // 加速渐变
            if (!key_pressed) {
                printf("加速渐变中...\n");
                key_pressed = 1;
            }
        } else if (key_status == 0 && key_pressed) {
            delay = NORMAL_DELAY;  // 恢复正常速度
            printf("恢复正常速度\n");
            key_pressed = 0;
        }
        
        // 控制渐变速度
        if (current_time - last_time >= delay) {
            last_time = current_time;
            
            if (step >= STEPS) {
                // 一轮渐变结束，选择新的目标颜色
                current_color = target_colors[target_index];
                target_index = simple_rand() % 8;  // 随机选择下一个目标颜色
                step = 0;
                printf("切换到新目标颜色: 0x%06x\n", target_colors[target_index]);
            }
            
            // 计算当前步骤应显示的颜色
            uint32_t target_color = target_colors[target_index];
            
            uint8_t r0 = get_r(current_color);
            uint8_t g0 = get_g(current_color);
            uint8_t b0 = get_b(current_color);
            
            uint8_t rk = get_r(target_color);
            uint8_t gk = get_g(target_color);
            uint8_t bk = get_b(target_color);
            
            // 线性插值计算
            uint8_t ri = r0 + (int)((rk - r0) * step) / STEPS;
            uint8_t gi = g0 + (int)((gk - g0) * step) / STEPS;
            uint8_t bi = b0 + (int)((bk - b0) * step) / STEPS;
            
            uint32_t display_color = make_color(ri, gi, bi);
            
            // 绘制当前颜色
            draw(display_color);
            
            step++;
        }
    }
    
    printf("屏保程序结束\n");
    return 0;
}