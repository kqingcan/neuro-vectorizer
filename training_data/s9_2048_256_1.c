#include "header.h"

int Out[2048][256];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<2048; i++) {
     for (j=0; j<256; j++) {
       Out[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Out[0][0], &Out[0][256]);
  BENCH("Example8",   example8(8), 2048, digest_memory(&Out[0][0], &Out[0][256]));
 
  return 0;
}