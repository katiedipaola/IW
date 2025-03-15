#include <stdio.h>
#define PI 3.14159265359
int main(void) {
  double a;
  scanf("%lf", &a);
  printf("%lf %lf\n", a * a * PI, 2 * a * PI);
  return 0;
}