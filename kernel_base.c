#include "kernel.h"
#include <assert.h>

void mul(double *A, double *B, double *C) {
  int i, j, k;
  for (i = 0; i < N; i ++)
    for (j = 0; j < N; j ++)
      for (k = 0; k < N; k ++)
        C[i*N+j] += A[i*N+k] * B[k*N+j];
}