#include <fixedptc.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main()
{
	// 测试muli mul divi div abs floor ceil要求测试尽可能多的情况，包括正负
	// 将预期结果记为常量，用assert验证
	fixedpt a = fixedpt_rconst(3.14);
	fixedpt b = fixedpt_rconst(2.0);
	fixedpt c = fixedpt_rconst(1.0);
	fixedpt d = fixedpt_rconst(0.5);
	fixedpt e = fixedpt_rconst(0.25);
	fixedpt f = fixedpt_rconst(0.125);
	fixedpt g = fixedpt_rconst(0.0625);
	assert(fixedpt_muli(a, 2) == fixedpt_rconst(6.28)); // 测试muli
	assert(fixedpt_mul(a, b) == fixedpt_rconst(6.28));
	assert(fixedpt_divi(a, 2) == fixedpt_rconst(1.57)); // 测试divi
	assert(fixedpt_div(a, b) == fixedpt_rconst(1.57));
	assert(fixedpt_abs(a) == fixedpt_rconst(3.14));	   // 测试abs
	assert(fixedpt_abs(-a) == fixedpt_rconst(3.14));   // 测试负数abs
	assert(fixedpt_floor(a) == fixedpt_rconst(3.0));   // 测试floor
	assert(fixedpt_ceil(a) == fixedpt_rconst(4.0));	   // 测试ceil
	assert(fixedpt_floor(-a) == fixedpt_rconst(-4.0)); // 测试负数floor
	assert(fixedpt_ceil(-a) == fixedpt_rconst(-3.0));  // 测试负数ceil
	assert(fixedpt_muli(b, 3) == fixedpt_rconst(6.0)); // 测试muli
	assert(fixedpt_mul(b, c) == fixedpt_rconst(2.0));
	assert(fixedpt_divi(b, 2) == fixedpt_rconst(1.0)); // 测试divi
	assert(fixedpt_div(b, c) == fixedpt_rconst(2.0));
	assert(fixedpt_abs(b) == fixedpt_rconst(2.0));	 // 测试abs
	assert(fixedpt_abs(-b) == fixedpt_rconst(2.0));	 // 测试负数abs
	assert(fixedpt_floor(b) == fixedpt_rconst(2.0)); // 测试floor
	assert(fixedpt_ceil(b) == fixedpt_rconst(2.0));	 // 测试ceil

	assert(fixedpt_floor(-b) == fixedpt_rconst(-2.0)); // 测试负数floor
	assert(fixedpt_ceil(-b) == fixedpt_rconst(-2.0));  // 测试负数ceil
	assert(fixedpt_muli(c, 4) == fixedpt_rconst(4.0)); // 测试muli
	assert(fixedpt_mul(c, d) == fixedpt_rconst(0.5));
	assert(fixedpt_divi(c, 2) == fixedpt_rconst(0.5)); // 测试divi
	assert(fixedpt_div(c, d) == fixedpt_rconst(2.0));
	assert(fixedpt_abs(c) == fixedpt_rconst(1.0));	   // 测试abs
	assert(fixedpt_abs(-c) == fixedpt_rconst(1.0));	   // 测试负数abs
	assert(fixedpt_floor(c) == fixedpt_rconst(1.0));   // 测试floor
	assert(fixedpt_ceil(c) == fixedpt_rconst(1.0));	   // 测试ceil
	assert(fixedpt_floor(-c) == fixedpt_rconst(-1.0)); // 测试负数floor
	assert(fixedpt_ceil(-c) == fixedpt_rconst(-1.0));  // 测试负数ceil
	assert(fixedpt_muli(d, 8) == fixedpt_rconst(4.0)); // 测试muli
	assert(fixedpt_mul(d, e) == fixedpt_rconst(0.125));
	assert(fixedpt_divi(d, 2) == fixedpt_rconst(0.25)); // 测试divi
	assert(fixedpt_div(d, e) == fixedpt_rconst(2.0));
	assert(fixedpt_abs(d) == fixedpt_rconst(0.5));		// 测试abs
	assert(fixedpt_abs(-d) == fixedpt_rconst(0.5));		// 测试负数abs
	assert(fixedpt_floor(d) == fixedpt_rconst(0.0));	// 测试floor
	assert(fixedpt_ceil(d) == fixedpt_rconst(1.0));		// 测试ceil
	assert(fixedpt_floor(-d) == fixedpt_rconst(-1.0));	// 测试负数floor
	assert(fixedpt_ceil(-d) == fixedpt_rconst(0.0));	// 测试负数ceil
														// e = 0.25, f = 0.125 g = 0.0625
	assert(fixedpt_muli(e, 16) == fixedpt_rconst(4.0)); // 测试muli
	assert(fixedpt_mul(e, f) == fixedpt_rconst(0.03125));
	assert(fixedpt_divi(e, 2) == fixedpt_rconst(0.125)); // 测试divi
	printf("e = %d, f = %d, e / f = %d\n", e, f, fixedpt_div(e, f));
	assert(fixedpt_div(e, f) == fixedpt_rconst(2.0));
	assert(fixedpt_abs(e) == fixedpt_rconst(0.25));
	assert(fixedpt_abs(-e) == fixedpt_rconst(0.25));   // 测试负数abs
	assert(fixedpt_floor(e) == fixedpt_rconst(0.0));   // 测试floor
	assert(fixedpt_ceil(e) == fixedpt_rconst(1.0));	   // 测试ceil
	assert(fixedpt_floor(-e) == fixedpt_rconst(-1.0)); // 测试负数floor
	assert(fixedpt_ceil(-e) == fixedpt_rconst(0.0));   // 测试负数
	assert(fixedpt_muli(f, 8) == fixedpt_rconst(1.0)); // 测试muli
	assert(fixedpt_mul(f, g) == fixedpt_rconst(0.0078125));
	assert(fixedpt_divi(f, 2) == fixedpt_rconst(0.0625)); // 测试divi
	printf("f = %d, g = %d, f / g = %d\n", f, g, fixedpt_div(f, g));
	assert(fixedpt_div(f, g) == fixedpt_rconst(2.0));
	assert(fixedpt_abs(f) == fixedpt_rconst(0.125));   // 测试abs
	assert(fixedpt_abs(-f) == fixedpt_rconst(0.125));  // 测试负数abs
	assert(fixedpt_floor(f) == fixedpt_rconst(0.0));   // 测试floor
	assert(fixedpt_ceil(f) == fixedpt_rconst(1.0));	   // 测试ceil
	assert(fixedpt_floor(-f) == fixedpt_rconst(-1.0)); // 测试负数floor
	assert(fixedpt_ceil(-f) == fixedpt_rconst(0.0));   // 测试负数ceil
	printf("Test passed!\n");
	return 0;
}