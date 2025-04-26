#include <stdio.h>

int main() {
  int i, N;
  long long K, A[100001];
  scanf("%d %lld", &N, &K);
  for (i = 1; i <= N; i++)
    scanf("%lld", &(A[i]));

  int j, k, l, count[60] = {};
  long long X[60] = {}, bit[60];
  for (i = 1, bit[0] = 1; i < 60; i++)
    bit[i] = bit[i - 1] << 1;
  for (i = 1; i <= N; i++) {
    for (j = 0; bit[j] <= K; j++) {
      if ((A[i] | bit[j]) == A[i])
        count[j]--;
      else
        count[j]++;
    }
  }
  for (k = 0; bit[k] <= K; k++)
    ;
  for (j = --k; j >= 0; j--)
    if (count[j] > 0 && X[0] + bit[j] <= K)
      X[0] += bit[j];
  for (i = 1, l = 0; l < k; i++) {
    X[i] = X[i - 1];
    for (; (X[i] | bit[l]) != X[i]; l++)
      ;
    X[i] ^= bit[l];
    for (j = l - 1; j >= 0; j--)
      if (count[j] > 0)
        X[0] |= bit[j];
  }

  long long ans = 0, sum;
  for (l = 0; l < i; l++) {
    sum = 0;
    for (j = 1; j <= N; j++)
      sum += (A[j] ^ X[l]);
    if (sum > ans)
      ans = sum;
  }
  printf("%lld\n", ans);
  fflush(stdout);
  return 0;
}