#include <stdio.h>
int MIN(int a, int b) { return a < b ? a : b; }
int main() {
  int n, m, s, t, u, i, j, k, d[1010][1010];
  while (scanf("%d %d %d %d %d", &n, &m, &s, &t, &u), n) {
    for (i = 0; i < 1010 * 1010; i++)
      d[i / 1010][i % 1010] = 1e8;
    for (i = 0; i < 1010; i++)
      d[i][i] = 0;
    while (m--) {
      scanf("%d %d %d", &i, &j, &k);
      d[i][j] = k;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        for (k = 1; k <= n; k++)
          d[j][k] = MIN(d[j][k], d[j][i] + d[i][k]);
      }
    }
    j = 1e9;
    for (i = 1; i <= n; i++)
      j = MIN(j, d[s][i] + d[i][t] + d[i][u]);
    printf("%d\n", j);
  }
  return 0;
}
