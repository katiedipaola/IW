#include <stdio.h>
#define INF 100000000

int main(void) {
  int n, m, a, b, cost, time, l, p, q, r;
  int i, j, k;
  int d[100][100];
  int exp[100][100];

  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0)
      break;

    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
        d[i][j] = INF;
        exp[i][j] = INF;
      }
    }
    for (i = 0; i < m; i++) {
      d[i][i] = 0;
      exp[i][i] = 0;
    }

    for (i = 0; i < n; i++) {
      scanf("%d %d %d %d", &a, &b, &cost, &time);
      d[a - 1][b - 1] = time;
      d[b - 1][a - 1] = time;
      exp[a - 1][b - 1] = cost;
      exp[b - 1][a - 1] = cost;
    }
    for (k = 0; k < m; k++) {
      for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
          if (d[i][j] > d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
          }
          if (exp[i][j] > exp[i][k] + exp[k][j]) {
            exp[i][j] = exp[i][k] + exp[k][j];
          }
        }
      }
    }
    scanf("%d", &l);
    for (i = 0; i < l; i++) {
      scanf("%d %d %d", &p, &q, &r);
      if (r == 0) {
        printf("%d\n", exp[p - 1][q - 1]);
      } else if (r == 1) {
        printf("%d\n", d[p - 1][q - 1]);
      }
    }
  }

  return 0;
}