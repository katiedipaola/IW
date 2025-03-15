#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int pow3[16], c[16];
  int n, m, i, j, k, d, x, y, p;

  pow3[0] = 1;
  for (i = 1; i <= 15; ++i) {
    pow3[i] = pow3[i - 1] * 3;
  }

  while (scanf("%d%d", &n, &m), n) {
    for (i = 0; i < 3; ++i) {
      for (scanf("%d", &j); j > 0; --j) {
        scanf("%d", &k);
        c[n - k] = i;
      }
    }

    p = 0;
    x = 0;
    for (i = n - 1; i >= 0; --i) {
      d = abs(p - c[i]);
      x += pow3[i] * d;
      if (d == 1) {
        p = 2 - p;
      }
    }

    y = pow3[n] - 1 - x;
    if (x > y) {
      x = y;
    }
    printf("%d\n", x > m ? -1 : x);
  }
  return 0;
}