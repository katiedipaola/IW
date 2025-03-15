#include <stdio.h>
#define Double double
#define Int int
#define For for
#define Scanf scanf
#define If if
#define Printf printf
#define Roop(i, n) for (i = 0; i < n; i++)
#define Roop2(i, n) for (i = 1; i <= n; i++)
#define Roop3(i, n) for (i = 2; i <= n; i++)

Double dp[101][101], x[101][101];

int main() {
  Int i, j, k, n, m;
  Double max = 0.0;
  while (scanf("%d%d", &n, &m), n + m) {
    Roop(i, n) Roop(j, n) Scanf("%lf", &x[i][j]);

    Roop2(i, n) Roop(j, n) dp[i][j] = (double)(i == 1);

    Roop3(i, m) Roop(j, n) Roop(k, n) If(dp[i][j] < dp[i - 1][k] * x[k][j])
        dp[i][j] = dp[i - 1][k] * x[k][j];

    max = 0.0;
    Roop(i, n) if (max < dp[m][i]) max = dp[m][i];

    Printf("%.2lf\n", max);
  }
  return 0;
}