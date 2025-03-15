#include <stdio.h>

int main(void) {
  int N, i;
  long long K = 0;
  long long M = 1000;
  scanf("%d", &N);
  int A[N];
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for (i = 0; i < N - 1; i++) {
    if (A[i] < A[i + 1]) {
      K = K + M / A[i];
      M = M % A[i];
    }
    if (A[i] > A[i + 1]) {
      M = M + K * A[i];
      K = 0;
    }
  }
  printf("%ld", M + K * A[N - 1]);
  return 0;
}