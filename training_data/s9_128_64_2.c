#include "header.h"

int Output[128][64];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<64; j++) {
       Output[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Output[0][0], &Output[0][64]);
  BENCH("Example8",   example8(8), 131072, digest_memory(&Output[0][0], &Output[0][64]));
 
  return 0;
}