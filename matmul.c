#include "kernel.h"
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define SEED 17

double A[N*N], B[N*N], C[N*N];

void init()
{
  srand(SEED);
  int i, j;
  for (i = 0; i < N; i ++)
    for (j = 0; j < N; j ++)
    {
      A[i*N+j] = (rand() % 100) / 2.0;
      B[i*N+j] = (rand() % 100) / 3.0;
      C[i*N+j] = 0.0;
    }
}

int main()
{
  int i, j;
  struct timeval t1, t2;
  double sum;
  double tall;

  init();

  // Start
  gettimeofday(&t1, NULL);
  mul(A, B, C);
  // End
  gettimeofday(&t2, NULL);

  // Verify
  sum = 0.0;
  for (i = 0; i < N; i ++)
    for (j = 0; j < N; j ++)
      sum += C[i*N+j] / (N * N);

  // Output performance
  tall = (double) (t2.tv_sec - t1.tv_sec) + 1e-6 * (t2.tv_usec - t1.tv_usec);
  printf("Verification (avg): %15lf\n", sum);
  printf("Total time (s):     %15lf\n", tall);

  return 0;
}