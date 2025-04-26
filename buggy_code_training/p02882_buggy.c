#include <math.h>
#include <stdio.h>

int main() {
  double A, B, x;
  double V, deg;

  scanf("%lf %lf %lf", &A, &B, &x);

  if ((x / (A * A)) - B >= 0) {
    deg = atan((2.0 * B - (2 * x / (A * A))) / A) * 180 / 3.14159265358;

    printf("%.9lf", deg);
  } else {
    deg = atan(A * B * B / (2 * x)) * 180 / 3.14159265358;
    printf("%.9lf", deg);
  }
  return 0;
}
