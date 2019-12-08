#include "header.h"

int G[1024][16384];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<1024; i++) {
     for (j=0; j<16384; j++) {
       G[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&G[0][0], &G[0][16384]);
  BENCH("Example8",   example8(8), 64, digest_memory(&G[0][0], &G[0][16384]));
 
  return 0;
}