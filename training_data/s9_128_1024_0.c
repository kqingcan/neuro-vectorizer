#include "header.h"

int G[128][1024];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<128; i++) {
     for (j=0; j<1024; j++) {
       G[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&G[0][0], &G[0][1024]);
  BENCH("Example8",   example8(8), 8192, digest_memory(&G[0][0], &G[0][1024]));
 
  return 0;
}