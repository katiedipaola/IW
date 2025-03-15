#include <math.h>
#include <stdio.h>

int main(void) {
  double a, b, C;
  double S, L, h, x;

  scanf("%lf %lf %lf\n", &a, &b, &C);
  if (C == 90.0f || C == -90.0f) {
    h = b;
    x = a;
  } else {
    h = b * acos(C * M_PI / 180.0);
    x = a - b * asin(C * M_PI / 180.0);
  }
  L = sqrt(x * x + h * h);
  S = a * h / 2;
  printf("%.8lf\n", S);
  printf("%.8lf\n", L + a + b);
  printf("%.8lf\n", h);

  return 0;
}