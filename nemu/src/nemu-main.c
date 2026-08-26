/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <common.h>
#include "monitor/sdb/sdb.h"
void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
void test_args();
int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
  //test_args();
  /* Start engine. */
  engine_start();
//0-5+(2+(2*9-(((5))))/((4/3))/(1+8)+0*0)
//((4*3*((1+2/4-((5))/7+(((7/(((((1-(((7+4*5/9/(0)+(((0+(8)+6)))+7*1-(0)-9+(2)-((3))+((9+(((((1)+0)))/(4))))/0-3*((8)/((1)-((6/2)*0))+((1))-0+8-(((0+4)))-(2*(((6))/(((4)))-((3*3))))))))*0)/5/4)+((5)))*7-(((1))))))*6)))))+((8/3/((5))))-3/5)
  return is_exit_status_bad();
}
// void test_args(){
//   int count=0;
//   uint32_t val,ans;
//   char s[65600]={};
//   char buffer[65600]={};
//   FILE* fp = fopen("/home/seaber/ysyx-workbench/nemu/tools/gen-expr/input","r");
//   if(fp!=NULL){

//     while(1){
//       memset(s,0,sizeof(s));
//       memset(buffer,0,sizeof(s));
//       if (fgets(buffer, sizeof(buffer), fp) != NULL) {
//           //printf("%s", buffer);
//       }else{
//         break;
//       }
//       sscanf(buffer,"%u",&ans);
//       strcpy(s,strchr(buffer,' ')+1);
//       //res=fscanf(fp,"%u %s\n",&ans,s);
//       bool success=true;
//       count++;
//       //printf("Get[%d]!\t%u\t%s\n",count,ans,s);
//       //printf("%s\n",s);
//       *strchr(s,'\n')='\0';
//       //printf("---%s---", s);
//       val=expr(s,&success);
//       if(success==true){
//         if(val==ans) printf("PASS[%d]\n",count);
//         else printf("WRONG[%d]\tANS:%u\tVAL:%u\t%s\n",count,ans,val,s);
//       }else{
//         printf("ERROR[%d]\tANS:%u\tVAL:%u\t%s\n",count,ans,val,s);
//       }
//     }
//   }else{
//     printf("No args tests.\n");
//   }
//   fclose(fp);
// }