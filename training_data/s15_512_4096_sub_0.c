#include "header.h"

int   ia[4096] ALIGNED16;
int A[512][4096];
int B[512][4096];

__attribute__((noinline))
void example13(int A[][4096], int B[][4096], int *out) {
  int i,j;
  for (i = 0; i < 512; i++) {
    int sub = 0;
    for (j = 0; j < 4096; j+=8) {
      sub += (A[i][j] -B[i][j]);
    }
    out[i] = sub;
  }
}
int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[4096]);
  init_memory(&A[0][0], &A[0][4096]);
  init_memory(&B[0][0],&B[0][4096]);
  BENCH("Example13",  example13(A,B,ia), 1024, digest_memory(&ia[0], &ia[4096]));
  return 0;
}