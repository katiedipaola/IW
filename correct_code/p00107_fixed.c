#include <math.h>
#include <stdio.h>
int main(void) {
  int x, y, z;
  for (;;) {
    scanf("%d%d%d", &x, &y, &z);
    if (x == 0)
      break;

    int n;
    scanf("%d", &n);

    int i;
    int r[10000];
    for (i = 0; i < n; i++) { //入力
      scanf("%d", &r[i]);
    }
    double a, b, a2, b2, c2, csub;
    if (x >= y && x >= z)
      a = y, b = z;
    else if (y >= x && y >= z)
      a = x, b = z;
    else if (z >= x && z >= y)
      a = x, b = y;
    a2 = a / 2;
    b2 = b / 2;
    csub = a2 * a2 + b2 * b2;
    c2 = sqrt(csub);
    // printf("%lf\n",c2);
    for (i = 0; i < n; i++) { //計算
      if (c2 < r[i])
        printf("OK\n", r[i]);
      else
        printf("NA\n", r[i]);
    }
  }

  return 0;
}