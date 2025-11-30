#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	uint32_t tag;
	int valid;
} matedata;

int main(int argc, char *argv[]) {
	static int n,m,w;
	static char *f;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	w = atoi(argv[3]);
	f = argv[4];
	matedata lines[(int)pow(2,(m - 2))][(int)pow(2,n)];
	int access_cnt = 0;
	int miss_cnt = 0;

	FILE *file = fopen(f, "r");
	if(!file) {
    perror("无法打开文件\n");
  }
  char line[12];
  while(fgets(line, sizeof(line), file)) {
		uint32_t pc;
    if(sscanf(line, "%x", &pc) == 1) {
			uint32_t index = (pc >> m & ((int)pow(2,(n - w)) - 1));
		  uint32_t tag = pc >> (m + n - w);
		  uint32_t offset = (pc & ((int)pow(2,m)-1)) / 4;
		//  printf("%x  ",pc);
		//	printf("%d,%d,%d  ",n,m,w);
		//	printf("index=%x,tag=%x,offset=%x  ",index,tag,offset);
			bool flag = false;
		  for(int i = 0; i < (int)pow(2,w); i ++) {
		    if(lines[offset][index * (int)pow(2,w) + i].tag == tag && lines[offset][index * (int)pow(2,w) + i].valid) {
		      access_cnt ++;
		      flag = true;
		    }
		  }
			if(!flag) {
		    miss_cnt ++;
				for(int j = (int)pow(2,w) - 1; j > 0; j --) {
		      lines[offset][index * (int)pow(2,w) + j].valid = lines[offset][index * (int)pow(2,w) + j - 1].valid;
		      lines[offset][index * (int)pow(2,w) + j].tag = lines[offset][index * (int)pow(2,w) + j - 1].tag;
				}
		    lines[offset][index * (int)pow(2,w)].valid = 1;
		    lines[offset][index * (int)pow(2,w)].tag = tag;
			}
		//	printf("access:%d\n",access_cnt);	
		}
	}
	fclose(file);

	int total_cnt = access_cnt + miss_cnt;
	double p = (double)access_cnt/(double)total_cnt;
	printf("************AMAT************\n");	
	printf("n=%d m=%d w=%d\n",n,m,w);
	printf("total:%d acess cnt:%d miss cnt:%d p:%.6f\n",total_cnt,access_cnt,miss_cnt,p);
	return 0;
}
