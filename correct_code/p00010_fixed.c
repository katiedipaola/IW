#include <math.h>
#include <stdio.h>
#define sq(x) (x) * (x)
int main(void) {
  int n, i;
  double a1, a2, b1, b2, c1, c2, x1, y1, x2, y2, x3, y3, x, y, r;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    a1 = 2 * (x2 - x1);
    b1 = 2 * (y2 - y1);
    c1 = sq(x1) - sq(x2) + sq(y1) - sq(y2);
    a2 = 2 * (x3 - x1);
    b2 = 2 * (y3 - y1);
    c2 = sq(x1) - sq(x3) + sq(y1) - sq(y3);
    x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
    y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
    r = sqrt(sq(x1 - x) + sq(y1 - y));
    printf("%.3f %.3f %.3f\n", x, y, r);
  }
  return 0;
}