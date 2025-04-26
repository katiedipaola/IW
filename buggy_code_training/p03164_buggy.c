#include <limits.h>
#include <stdio.h>

long long int chmin(long long int a, long long int b) {
  // b -> min
  if (a < b) {
    b = a;
  }
  return b;
}

int main() {
  int n, max_w;
  scanf("%d%d", &n, &max_w);
  int w[n], v[n], max_v = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &w[i], &v[i]);
    max_v += v[i];
  }
  long long int dp[n + 1][max_v + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= max_v; j++) {
      dp[i][j] = 1LL << 60;
    }
  }
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int value = 0; value < max_v; value++) {
      if (value - v[i] >= 0) {
        dp[i + 1][value] = chmin(dp[i + 1][value], dp[i][value - v[i]] + w[i]);
      }
      dp[i + 1][value] = chmin(dp[i + 1][value], dp[i][value]);
    }
  }

  for (int check = max_v; check >= 0; check--) {
    if (dp[n][check] <= max_w) {
      printf("%d", check);
      break;
    }
  }

  // printf("%d",max_v);
  // printf("%lld",dp[n][31]);

  return 0;
}
