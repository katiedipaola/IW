#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  int a, b, h, m;

  scanf("%d%d%d%d", &a, &b, &h, &m);

  double rad = 0;
  double ans;

  double l, s;

  l = m * 6;
  s = h * 30 + 0.5 * m;

  rad = fabs(l - s);
  if (rad >= 180.0) {
    rad = 360.0 - rad;
  }
  if (rad == 0.0) {
    ans = abs(a - b);
  } else {
    ans = a * a + b * b - 2 * a * b * cos(rad * M_PI / 180);
    ans = sqrt(ans);
  }

  printf("%.20f\n", ans);
  return 0;
}