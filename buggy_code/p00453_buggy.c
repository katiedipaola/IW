#include <stdio.h>
#include <stdlib.h>
#define MAX_R (3000000)
#define min(x, y) ((x < y) ? x : y)
typedef struct stone {
  int x, r;
} Stone;
Stone p[155][15];
int xn[155], dp[155][15][80];
int main() {
  int i, j, k, h, n, m, x, y, z, ans;
  while (1) {
    scanf("%d%d", &n, &m);
    if (n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &xn[i]);
      for (j = 0; j < xn[i]; j++) {
        scanf("%d%d", &p[i][j].x, &p[i][j].r);
        for (k = 0; k <= m; k++)
          dp[i][j][k] = MAX_R;
      }
    }
    for (i = 0; i < xn[0]; i++)
      dp[0][i][0] = 0;
    for (i = 0; i < xn[1]; i++)
      dp[1][i][1] = 0;
    for (i = 0; i < n - 1; i++) {
      for (h = 0; h <= m; h++) {
        for (j = 0; j < xn[i]; j++) {
          for (k = 0; k < xn[i + 1]; k++) {
            y = (p[i][j].r + p[i + 1][k].r) * abs(p[i][j].x - p[i + 1][k].x);
            dp[i + 1][k][h] = min(dp[i + 1][k][h], dp[i][j][h] + y);
          }
          for (k = 0; k < xn[i + 2]; k++) {
            y = (p[i][j].r + p[i + 2][k].r) * abs(p[i][j].x - p[i + 2][k].x);
            dp[i + 2][k][h + 1] = min(dp[i + 2][k][h], dp[i][j][h] + y);
          }
        }
      }
    }
    ans = MAX_R;
    for (i = 0; i <= m; i++)
      for (j = 0; j < xn[n - 1]; j++)
        ans = min(ans, dp[n - 1][j][i]);
    for (i = 0; i < m; i++)
      for (j = 0; j < xn[n - 2]; j++)
        ans = min(ans, dp[n - 2][j][i]);

    printf("%d\n", ans);
  }
  return 0;
}