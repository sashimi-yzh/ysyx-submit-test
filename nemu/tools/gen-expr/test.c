#include <stdio.h>
#include <stdint.h>

int main() {

  unsigned int result = (unsigned int)7+(unsigned int)((32-19*(75))*51/91/22);
  printf("Result of  (unsigned int): %u\n", result);

  uint32_t new_result = (unsigned int)7 + 
	((unsigned int)32 - (unsigned int)19 * (unsigned int)75) * 
	(unsigned int)51 / (unsigned int)91 / (unsigned int)22;
  printf("mid Result %u\n", new_result);

  uint32_t result_2 = ((96))*60-((54)/(88)/59/9)/(54/0*(22));
  printf("result2 %u\n", result_2);

  return 0;
}
