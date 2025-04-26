#include <stdio.h>
#include <stdlib.h>

#define W 100
#define H 100
#define MAX(A, B) ((B) > (A) ? (B) : (A))

int main(int argc, char *argv[]) {
  int i, j, k;

  for (;;) {
    int d[W + 1][H + 1] = {};
    int w, h, s, t;
    int res = 0;
    int n;

    scanf("%d", &n);
    if (n == 0)
      break;
    scanf("%d%d", &w, &h);
    while (n--) {
      int x, y;

      scanf("%d%d", &x, &y);
      d[x][y] = 1;
    }
    for (i = 1; i <= w; ++i)
      for (j = 1; j <= h; ++j)
        d[i][j] += d[i][j - 1];
    scanf("%d%d", &s, &t);

    for (i = 1; i + s <= w; ++i)
      for (j = 0; j + t <= h; ++j) {
        int tmp = 0;

        for (k = i; k <= i + s; ++k)
          tmp += d[k][j + t] - d[k][j];

        res = MAX(res, tmp);
      }

    printf("%d\n", res);
  }

  return (EXIT_SUCCESS);
}