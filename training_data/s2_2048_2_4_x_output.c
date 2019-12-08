
#include "header.h"
int output[2048] ALIGNED16;
__attribute__((noinline))
void example2a (int x) {
   int i;

   /* feature: support for unknown loop bound  */
   /* feature: support for loop invariants  */
   for (i=0; i< 2048-3 ; i+=4) {
      output[i] = x;
output[i+1] = -x;
output[i+2]=x;
output[i+3]=-x;
   }
}
int main(int argc,char* argv[]){
 
  init_memory(&output[0], &output[2048]);
  BENCH("Example2a",  example2a(2), Mi*4/2048*512, digest_memory(&output[0], &output[2048]));
  
  return 0;
}