#include <stdio.h>
#include <string.h>

int dp[31][31], n, i, j, k, r;

int main() {

  for (; scanf("%d", &n), n;) {
    r = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for (i = 1; i < n; i++)
      for (j = 0; j < n; j++) {
        for (k = -1; k >= -3; k--)
          if (j + k >= 0)
            dp[i][j] += dp[i - 1][j + k];
      }
    for (i = 0; i < n; i++)
      r += dp[i][n - 1];
    printf("%d\n", r / 3650 + (r % 3650 ? 1 : 0));
  }
  return 0;
}