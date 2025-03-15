#include <stdio.h>

int main() {
  long long N, M, i;
  scanf("%lld%lld", &N, &M);
  long long P[M], Y[M], C[M], A[M];
  long long count[N + 1];
  for (i = 0; i < M; i++) {
    scanf("%lld%lld", &P[i], &Y[i]);
    C[i] = i;
  }
  for (i = 0; i <= N; i++)
    count[i] = 0;

  // sort
  long long h = M;
  long long swapped = 0;
  while (h > 1 || swapped == 1) {
    if (h > 1)
      h = h * 10 / 13;
    swapped = 0;
    for (i = 0; i < M - h; i++) {
      if (Y[i] > Y[i + h]) {
        long long tmp = Y[i];
        Y[i] = Y[i + h];
        Y[i + h] = tmp;
        tmp = P[i];
        P[i] = P[i + h];
        P[i + h] = tmp;
        tmp = C[i];
        C[i] = C[i + h];
        C[i + h] = tmp;
        swapped = 1;
      }
    }
  }

  for (i = 0; i < M; i++) {
    count[P[i]]++;
    A[C[i]] = P[i] * 1000000 + count[P[i]];
  }
  for (i = 0; i < M; i++) {
    if (A[i])
      printf("%012lld\n", A[i]);
  }
  return 0;
}