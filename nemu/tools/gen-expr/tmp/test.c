#include <stdio.h>
#include <stdlib.h>

int main(){
	int ret = system("gcc .code.c -o .expr -Werror");
	printf("%d\n",ret);
	return 0;
}
