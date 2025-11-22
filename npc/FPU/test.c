//Add option -lm while compile.
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>
#include <time.h>
#pragma STDC FENV_ACCESS ON
//#define FRM 3

typedef union {
    float f;
    uint32_t u;
} FloatUnion;

enum Opcode {
    FADD = 0x09,    // 匹配 fpu.v 的 FADD_S
    FSUB = 0x0A,    // 匹配 FSUB_S
    FMUL = 0x0B,    // 匹配 FMUL_S
    FDIV = 0x0C,    // 匹配 FDIV_S
    FSGNJ = 0x05,   // 匹配 FSGNJ_S
    FSGNJN = 0x06,  // 匹配 FSGNJN_S
    FSGNJX = 0x07,  // 匹配 FSGNJX_S
    FEQ = 0x0F,     // 匹配 FEQ_S
    FLT = 0x11,     // 匹配 FLT_S
    FLE = 0x10,     // 匹配 FLE_S
    FMIN = 0x0D,    // 匹配 FMIN_S
    FMAX = 0x0E     // 匹配 FMAX_S
};

void generate_test_case(FILE *fout, uint8_t sel, float a, float b, uint8_t frm) {
    
    FloatUnion A, B, R;
    A.f = a;
    B.f = b;

    uint32_t fflags = 0;
    double exact_result = 0.0;
    if (sel == FADD) exact_result = (double)a + (double)b;
    else if (sel == FSUB) exact_result = (double)a - (double)b;
    else if (sel == FMUL) exact_result = (double)a * (double)b;
    else if (sel == FDIV && b != 0.0f) exact_result = (double)a / (double)b;
    feclearexcept(FE_ALL_EXCEPT);
    switch (sel) {
    	case FMUL:
            R.f = a*b;
            break;
        case FDIV:
            R.f = a/b;
            break;	
        case FADD:
            R.f = a + b;
            break;
        case FSUB:
            R.f = a - b;
            break;
        case FMIN:
            R.f = fminf(a, b);
            break;
        case FMAX:
            R.f = fmaxf(a, b);
            break;
        case FEQ:
            R.u = (a == b) ? 1 : 0;
            break;
        case FLT:
            R.u = (a < b) ? 1 : 0;
            break;
        case FLE:
            R.u = (a <= b) ? 1 : 0;
            break;
        case FSGNJ:
            R.u = (A.u & 0x7fffffff) | ( B.u & 0x80000000);
            break;
				case FSGNJN:
            R.u = (A.u & 0x7fffffff) | (~B.u & 0x80000000);
            break;
				case FSGNJX:
            R.u = A.u ^ (B.u & 0x80000000);
            break;
        default:
            R.f = 0.0f;
            break;
    }
    if (isnan(R.f)) fflags |= 0x10;  // NV (无效操作)
    if (isinf(R.f)) fflags |= 0x08;  // OF (溢出)
    if ((sel == FADD || sel == FSUB || sel == FMUL || sel == FDIV) && fabs(exact_result) > 0.0 && fabs(exact_result) < 1.17549435e-38) fflags |= 0x04; // UF

    if ((sel == FADD || sel == FSUB || sel == FMUL || sel == FDIV) &&  fetestexcept(FE_INEXACT))  fflags |= 0x01;  // NX 


   fprintf(fout, "%02x%08x%08x%01x%08x%02x\n", sel, A.u, B.u, frm, R.u, fflags);
}

int main() {
    srand(time(NULL)); 
  //设置浮点舍入模式
	//fesetround(FE_TONEAREST);	//0		
	//fesetround(FE_TOWARDZERO);   //1
	//fesetround(FE_DOWNWARD);   //2
	//fesetround(FE_UPWARD);    //3

	FILE *fout = fopen("./fpu_test_vector.hex", "w");
	if(!fout) {
		perror("fopen");
		return 1;
	}

	for(int i = 0; i < 100000; i++) {
		float a = ((float)rand() / RAND_MAX) * 100.0f - 50.0f;
		float b = ((float)rand() / RAND_MAX) * 100.0f - 50.0f;
		uint8_t op = rand() % 11 ;
		//uint8_t op = 0x0C;

        int frm=rand()%4;
        switch(frm){
            case 0:
                fesetround(FE_TONEAREST);
                break;
            case 1:
                fesetround(FE_TOWARDZERO); 
                break;
            case 2:
                fesetround(FE_DOWNWARD);
                break;
            default:
                fesetround(FE_UPWARD);
                break;
        }
		switch(op){
            case 0:
                op=0x09;
            case 1:
                op=0x0A;
                break;
            case 2:
                op=0x0B;
            case 3:
                op=0x0C;
                break;
            case 4:
                op=0x05;
            case 5:
                op=0x06;
            case 6:
                op=0x07;
                break;
            case 7:
                op=0x11;
            case 8:
                op=0x0E;
            case 9:
                op=0x0D;
                break;
            case 10:
                op=0x010;
                break;
            default:
                op=0x0F;
                break;
        }
		//uint8_t frm = FRM;

		generate_test_case(fout, op, a, b, frm);
	}

	fclose(fout);
	printf("Test vector written to fpu_test_vector.hex\n");
	return 0;
}
