#include <stdio.h>
#include <stdint.h>
int main() {   
	//unsigned result = (uint32_t)4*(((uint32_t)8>=(uint32_t)1)>=((((uint32_t)1)==((uint32_t)8))-((uint32_t)1-(uint32_t)8-(uint32_t)6+(uint32_t)3!=(uint32_t)1==(uint32_t)1+(uint32_t)1<=(uint32_t)8&&(uint32_t)9*(uint32_t)6))); 
	//unsigned result = (uint32_t)4*(((uint32_t)8>=(uint32_t)1)>=((((uint32_t)1)==((uint32_t)8))-((uint32_t)1))); 
	//unsigned result = ((uint32_t)1-(uint32_t)8-(uint32_t)6+(uint32_t)3!=(uint32_t)1==(uint32_t)1+(uint32_t)1<=(uint32_t)8&&(uint32_t)9*(uint32_t)6);
	//unsigned result = 1-8-6+3!=1==1+1<=8&&9*6;  
	//uint32_t result = (((uint32_t)1==(uint32_t)8)-((uint32_t)0<=(uint32_t)8));
	//uint32_t ansa = ((uint32_t)8>=(uint32_t)1)>=result;
	//uint32_t ansb = ((uint32_t)8>=(uint32_t)1)>=(((uint32_t)1==(uint32_t)8)-((uint32_t)0<=(uint32_t)8));
	uint32_t result = (((uint32_t)4)<=(uint32_t)0&&(uint32_t)4/(uint32_t)3-((uint32_t)1)+(uint32_t)4-(uint32_t)0==(uint32_t)7+((uint32_t)9)/(((uint32_t)2/(uint32_t)0))-(((uint32_t)8))-(uint32_t)0*((uint32_t)1-(uint32_t)1));
	//printf("%u,%u\n", ansa, ansb);   
	printf("%u,%u\n", result, (((uint32_t)1==(uint32_t)8)-((uint32_t)0<=(uint32_t)8)));   
	return 0; 
}
