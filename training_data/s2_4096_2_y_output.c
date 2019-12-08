
#include "header.h"
int output[4096] ALIGNED16;
__attribute__((noinline))
void example2a (int y) {
   int i;

   /* feature: support for unknown loop bound  */
   /* feature: support for loop invariants  */
   for (i=0; i< 4096 ; i+=2) {
      output[i] = y;
   }
}
int main(int argc,char* argv[]){
 
  init_memory(&output[0], &output[4096]);
  BENCH("Example2a",  example2a(2), Mi*4/4096*512, digest_memory(&output[0], &output[4096]));
  
  return 0;
}