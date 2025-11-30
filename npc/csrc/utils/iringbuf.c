#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IRB_SIZE 500
#define iringbuf_is_empty() (head == tail)
#define iringbuf_is_full() (((tail+1)%IRB_SIZE) == head )

char strarray[IRB_SIZE]={0};
  unsigned head;
  unsigned tail;

int iringbuf_init() {
   head = 0;
   tail = 0;
   return 0;
}
 
int iringbuf_push(char *data) {
	int len = strlen(data);
	for(int i = 0; i < len; i ++) {
		strarray[tail] = data[i];
		tail = (tail + 1) % IRB_SIZE;
    if(iringbuf_is_full()) {
			head = (head + 1) % IRB_SIZE;
    }
	}
    return 0;
}
 
void iringbuf_display() {
  if(iringbuf_is_empty()) {
    printf("iringbuf is empty.\n");
    return;
  }
  while(head != tail){
    printf("%c", strarray[head]); 
		head = (head + 1)%(IRB_SIZE);
  }
  printf("\n");
  return;
}

