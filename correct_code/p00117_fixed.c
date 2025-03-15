#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int i, j, k, n, m, l, x, y, route[2][21][21];

int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j)
        route[0][i][j] = 999999999;
    }
  }

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d,%d,%d,%d", &j, &k, &x, &y);
    route[0][j - 1][k - 1] = x;
    route[0][k - 1][j - 1] = y;
  }

  for (l = 1; pow(2.0, l - 1) < n - 1; l++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        route[l % 2][i][j] = route[(l + 1) % 2][i][j];
        for (k = 0; k < n; k++) {
          if (route[l % 2][i][j] >
              route[(l + 1) % 2][i][k] + route[(l + 1) % 2][k][j]) {
            route[l % 2][i][j] =
                route[(l + 1) % 2][i][k] + route[(l + 1) % 2][k][j];
          }
        }
      }
    }
  }

  l = (l - 1) % 2;

  scanf("%d,%d,%d,%d", &x, &y, &j, &k);
  printf("%d\n", j - k - route[l][x - 1][y - 1] - route[l][y - 1][x - 1]);

  return 0;
}