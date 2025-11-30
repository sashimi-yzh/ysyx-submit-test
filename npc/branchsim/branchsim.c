#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	uint32_t tag;
} matedata;

int n = 3;
int w = 2;

int bbt(uint32_t pc, matedata *liness) {
	uint32_t index = (pc >> 2 & ((int)pow(2,(n - w)) - 1));
	uint32_t tag = pc >> (2 + n - w);
	bool flag = false;
		for(int i = 0; i < (int)pow(2,w); i ++) {
		  if(liness[index * (int)pow(2,w) + i].tag == tag) {
		    flag = true;
				return 1;
		  }
		}
		if(!flag) {
			for(int j = (int)pow(2,w) - 1; j > 0; j --) {
		    liness[index * (int)pow(2,w) + j].tag = liness[index * (int)pow(2,w) + j - 1].tag;
			}
		  liness[index * (int)pow(2,w)].tag = tag;
		}
	return 0;
}

int64_t branch_total_cnt = 0;
int64_t branch_right_cnt = 0;
int64_t jal_total_cnt = 0;
int64_t jal_right_cnt = 0;
uint32_t ppc = 0x30000000;
uint32_t pinst = 0x0;

int main(int argc, char *argv[]) {
	FILE *file = fopen(argv[1], "r");
	if(!file) {
    perror("无法打开文件\n");
  }
	matedata liness[(int)pow(2,n)];
	char line[32];
	while(fgets(line, sizeof(line), file)) {
		uint32_t pc;
		uint32_t inst;
		if(sscanf(line, "%x %x", &pc, &inst) == 2);
		if((pinst & 0b1111111) ==  0b1100011) {
			bool offset = (pinst >> 31) & 0b1;
			bool hit = false;
			if(offset) {
				if(bbt(ppc,liness)) {
					hit = true;
				}
			}
			if(((pc != (ppc + 4)) && hit && offset) || ((pc == (ppc + 4)) && !offset) || ((pc == (ppc + 4)) && !hit && offset)) {
			//if(pc == ppc + 4) {
				branch_right_cnt ++;
			}
			else {
				//printf("branch pre err: pc=%08x\n",ppc);
			}
			branch_total_cnt ++; 
		}
		if((pinst & 0b1111111) ==  0b1101111) {
      if(bbt(ppc,liness) || ((pc == ppc + 4))) {
        jal_right_cnt ++;
      }
			else {
				//printf("jal pre err: pc=%08x\n",ppc);
			}
      jal_total_cnt ++;
    }

		ppc = pc;
		pinst = inst;
	}
	fclose(file);

	double branch_p = (double)branch_right_cnt/(double)branch_total_cnt;
	double jal_p = (double)jal_right_cnt/(double)jal_total_cnt;
	printf("************************\n");	
	printf("branch total=%ld branch right=%ld p=%.6f\n",branch_total_cnt,branch_right_cnt,branch_p);
	printf("jal total=%ld jal right=%ld p=%.6f\n",jal_total_cnt,jal_right_cnt,jal_p);
	return 0;
}
