#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[100] = "50456 5000+ 450 +6\n";
	int result = 0;
	char *e = malloc(100*sizeof(char));

	sscanf(s, "%d %[^\n]", &result, e);
	printf("result = %d, expression = %s", result, e);

	free(e);

	return 0;
}
