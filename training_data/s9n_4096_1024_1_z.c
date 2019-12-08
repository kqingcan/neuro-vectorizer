#include "header.h"

int Out[4096][1024];
__attribute__((noinline))
void example8 (int z) {
   int i,j;

   /* feature: support for multidimensional arrays  */
   for (i=0; i<4096-1; i+=2) {
     for (j=0; j<1024-1; j+=2) {
       Out[i][j] = z;
       Out[i+1][j] = z;
       Out[i][j+1] = z;
       Out[i+1][j+1] = z;

     }
   }
}


int main(int argc,char* argv[]){
  init_memory(&Out[0][0], &Out[0][1024]);
  BENCH("Example8",   example8(8), 256, digest_memory(&Out[0][0], &Out[0][1024]));
 
  return 0;
}