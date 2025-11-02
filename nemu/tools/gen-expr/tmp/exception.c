#include <stdio.h>
int main() {   
		unsigned result1 = 8/(-2);
		unsigned result2 = 8/(unsigned)(-2);
		unsigned result3 = (unsigned) 8/(-2);
		unsigned result4 = (unsigned) (8/(-2));//equal to 1
		printf("%u\n", result1);
		printf("%u\n", result2);
		printf("%u\n", result3);
		printf("%u\n", result4);

		return 0; 
}
