// output hello per 0.5 seconds
// by gettimeofday
#include <stdio.h>
#include <NDL.h>
void sleep_for(double seconds)
{
	uint32_t start = NDL_GetTicks();
	uint32_t end;
	do
	{
		end = NDL_GetTicks();
	} while (end - start < seconds * 1000);
}
int main()
{
	NDL_Init(0);
	while (1)
	{
		printf("Hello World from Navy-apps!\n");
		sleep_for(0.5);
	}
	return 0;
}