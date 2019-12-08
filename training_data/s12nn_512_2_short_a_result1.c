#include "header.h"

short short_a[512];
short short_b[512];
short short_c[512];
int   result1[512] ALIGNED16;
int   result2[512] ALIGNED16;
int   result3[512] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ short_a, short *__restrict__ short_b, short *__restrict__ short_c, int* __restrict__ result1, int* __restrict__ result2, int* __restrict__ result3) {
  int i;
  for (i = 0; i < 512; i+=2) {
    result1[i] = (int) short_a[i];
    result2[i] = (int) short_b[i];
    result3[i] = (int) short_c[i];
  }
}
int main(int argc,char* argv[]){
  init_memory(&result1[0], &result1[512]);
  init_memory(&result2[0], &result2[512]);
  init_memory(&result3[0], &result3[512]);
  init_memory(&short_a[0], &short_a[512]);
  init_memory(&short_b[0], &short_b[512]);
  init_memory(&short_c[0], &short_c[512]);
  BENCH("Example10b", example10b(short_a,short_b,short_c,result1,result2,result3), Mi*4/512*512, digest_memory(&result1[0], &result1[512])+digest_memory(&result2[0], &result2[512])+digest_memory(&result3[0], &result3[512]));
 
  return 0;
}