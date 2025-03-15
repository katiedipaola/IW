#include <stdio.h>
#define Nu 50
#define SUM_MAX 3000

long long int dp[Nu + 1][Nu + 1][SUM_MAX + 1] = {0};

int main(void) {
  int i;
  int j;
  int k;
  int n;
  int a;
  int x[Nu + 1];
  int k_max;
  long long int ans = 0;
  scanf("%d %d", &n, &a);
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (i = 0; i < n + 1; i++) {
    dp[i][0][0] = 1;
  }
  for (i = 0; i < n; i++) {
    k_max = (i + 1) * 50;
    for (j = 0; j <= i; j++) {
      for (k = 0; k < k_max + 1; k++) {
        if (k >= x[i]) {
          dp[i + 1][j + 1][k] = dp[i][j][k - x[i]] + dp[i][j + 1][k];
        } else {
          dp[i + 1][j + 1][k] = dp[i][j + 1][k];
        }
      }
    }
  }
  for (i = 1; i < n; i++) {
    ans += dp[n][i][i * a];
  }
  printf("%I64d", ans);
}