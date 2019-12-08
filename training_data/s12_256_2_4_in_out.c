#include "header.h"

short in[256];
int   out[256] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ in, int* __restrict__ out) {
  int i;
  for (i = 0; i < 256-3; i+=4) {
    out[i] = (int) in[i];
out[i+1] = (int) in[i+1];
out[i+2] = (int) in[i+2];
out[i+3] = (int) in[i+3];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out[0], &out[256]);
  init_memory(&in[0], &in[256]);
  BENCH("Example10b", example10b(in,out), Mi*4/256*512, digest_memory(&out[0], &out[256]));
 
  return 0;
}