#include <math.h>
#include <stdio.h>

int main(void) {
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  printf("%.6lf\n", sqrt(pow(x2 - x1, 2) + pow(x2 - x1, 2)));
  return 0;
}