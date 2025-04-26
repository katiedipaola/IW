#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int long N;
  int long A[100000];
  int i;
  int minus;
  minus = 0;

  int cmp(const void *p, const void *q) {
    return *(long int *)p - *(long int *)q;
  }

  scanf("%ld", &N);

  for (i = 0; i < N; i++) {
    scanf("%ld", &A[i]);
  }

  qsort(A, N, sizeof(long int), cmp);

  for (i = 0; i < N; i++) {
    if (A[i] == A[i + 1]) {
      minus += 1;
    }
  }

  printf("%ld\n", N - minus * 2);
}
