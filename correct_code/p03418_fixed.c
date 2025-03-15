#include <stdio.h>

int main() {
  long long N, K, ans = 0;
  scanf("%lld%lld", &N, &K);

  for (long long b = K + 1; b <= N; b++) {
    long long p = N / b;
    long long q = N % b - K + 1;
    if (q < 0)
      q = 0;
    ans += (b - K) * p + q;
    if (K == 0)
      ans--;
  }
  printf("%lld\n", ans);
  return 0;
}