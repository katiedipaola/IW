#include <stdio.h>
#define mod 1000000007
long long int kai(int n) {
  if (n == 0) {
    return 1;
  } else {
    return (n * kai(n - 1)) % mod;
  }
}
int main(void) {
  int N, K, q, w, e, r, t, y, u, i, o, p, aans = 0;
  long long int ans = 0;
  int A[100];
  long long int dp[101][256] = {0};
  long long int dps[101][256] = {0};
  scanf("%d %d", &N, &K);
  for (q = 0; q < N; q++) {
    scanf("%d", &w);
    A[q] = w;
  }
  dp[0][0] = 1;
  dps[0][0] = 1;
  for (q = 0; q < N; q++) {       //全体のループ
    for (w = 1; w <= N; w++) {    //何個使ったか
      for (e = 0; e < 256; e++) { //ここまでのぉｒ
        dps[w][e ^ A[q]] += dp[w - 1][e];
      }
    }
    for (w = 0; w <= N; w++) {
      for (e = 0; e < 255; e++) {
        dp[w][e] = dps[w][e] % mod;
      }
    }
  }
  ans = 0;
  for (q = 0; q <= N; q++) {
    ans += dp[q][K] * kai(q);
    ans %= mod;
  }
  printf("%lld\n", ans % mod);
  return 0;
}