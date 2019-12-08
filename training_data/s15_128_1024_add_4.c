#include "header.h"

int   ia[1024] ALIGNED16;
int op1[128][1024];
int op2[128][1024];

__attribute__((noinline))
void example13(int op1[][1024], int op2[][1024], int *out) {
  int i,j;
  for (i = 0; i < 128; i++) {
    int sum_add = 0;
    for (j = 0; j < 1024; j+=8) {
      sum_add += (op1[i][j] +op2[i][j]);
    }
    out[i] = sum_add;
  }
}
int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[1024]);
  init_memory(&op1[0][0], &op1[0][1024]);
  init_memory(&op2[0][0],&op2[0][1024]);
  BENCH("Example13",  example13(op1,op2,ia), 16384, digest_memory(&ia[0], &ia[1024]));
  return 0;
}