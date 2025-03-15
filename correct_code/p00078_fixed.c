#include <stdio.h>

int main(void) {
  int m[20][20], i, l, n, x, y;

  while (scanf("%d", &n) != 0) {
    if (n == 0)
      break;
    for (i = 0; i < 20; i++) {
      for (l = 0; l < 20; l++) {
        m[i][l] = 0;
      }
    }

    x = (n - 1) / 2;
    y = x + 1;

    m[x][y] = 1;

    for (i = 2; i <= n * n; i++) {
      x += 1;
      y += 1;
      while (1) {
        if (x >= n) {
          x = 0;
          continue;
        }
        if (x < 0) {
          x = n - 1;
          continue;
        }
        if (y >= n) {
          y = 0;
          continue;
        }
        if (y < 0) {
          y = n - 1;
          continue;
        }
        if (m[x][y] > 0) {
          x -= 1;
          y += 1;
          continue;
        }
        break;
      }
      m[x][y] = i;
    }

    for (i = 0; i < n; i++) {
      for (l = 0; l < n; l++) {
        printf("%4d", m[l][i]);
      }
      printf("\n");
    }
  }
  return 0;
}
