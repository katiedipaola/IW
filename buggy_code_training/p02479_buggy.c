#include <stdio.h>
#define PI 3.14159265359
int main(void) {
  int a;
  scanf("%d", &a);
  printf("%lf %lf\n", a * a * PI, 2 * a * PI);
  return 0;
}