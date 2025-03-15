#include <stdio.h>
#include <string.h>

char X[1001], Y[1001];

int LCS_Length(void) {
  int i, j;
  int m = strlen(X);
  int n = strlen(Y);
  int c[m + 1][n + 1];

  for (i = 1; i <= m; i++)
    c[i][0] = 0;
  for (j = 0; j <= n; j++)
    c[0][j] = 0;

  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (X[i - 1] == Y[j - 1])
        c[i][j] = c[i - 1][j - 1] + 1;
      else if (c[i - 1][j] >= c[i][j - 1])
        c[i][j] = c[i - 1][j];
      else
        c[i][j] = c[i][j - 1];
    }
  }
  return c[m][n];
}

main() {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s%s", X, Y);
    printf("%d\n", LCS_Length());
  }
  return 0;
}