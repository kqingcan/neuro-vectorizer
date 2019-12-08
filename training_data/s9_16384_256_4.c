#include "header.h"

int assign[16384][256];
__attribute__((noinline))
void example8 (int x) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<16384; i++) {
     for (j=0; j<256; j++) {
       assign[i][j] = x;
     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&assign[0][0], &assign[0][256]);
  BENCH("Example8",   example8(8), 256, digest_memory(&assign[0][0], &assign[0][256]));
 
  return 0;
}