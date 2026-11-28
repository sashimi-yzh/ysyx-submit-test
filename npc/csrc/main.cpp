#include <stdio.h>
#include <engine.h>

int main(int argc,char**argv) {

  init_engine(argc,argv);
  start_engine();

  printf("end!!!\n");
  return 1;
}