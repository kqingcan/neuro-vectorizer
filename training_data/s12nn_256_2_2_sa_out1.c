#include "header.h"

short sa[256];
short sb[256];
short sc[256];
int   out1[256] ALIGNED16;
int   out2[256] ALIGNED16;
int   out3[256] ALIGNED16;

__attribute__((noinline))
void example10b(short *__restrict__ sa, short *__restrict__ sb, short *__restrict__ sc, int* __restrict__ out1, int* __restrict__ out2, int* __restrict__ out3) {
  int i;
  for (i = 0; i < 256-1; i+=2) {
    out1[i] = (int) sa[i];
out1[i+1] = (int) sa[i+1];
    out2[i] = (int) sb[i];
out2[i+1] = (int) sb[i+1];
    out3[i] = (int) sc[i];
out3[i+1] = (int) sc[i+1];
  }
}
int main(int argc,char* argv[]){
  init_memory(&out1[0], &out1[256]);
  init_memory(&out2[0], &out2[256]);
  init_memory(&out3[0], &out3[256]);
  init_memory(&sa[0], &sa[256]);
  init_memory(&sb[0], &sb[256]);
  init_memory(&sc[0], &sc[256]);
  BENCH("Example10b", example10b(sa,sb,sc,out1,out2,out3), Mi*4/256*512, digest_memory(&out1[0], &out1[256])+digest_memory(&out2[0], &out2[256])+digest_memory(&out3[0], &out3[256]));
 
  return 0;
}