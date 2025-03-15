#include <math.h>
#include <stdio.h>

int main(void) {

  double i;
  double ans;

  scanf("%lf", &i);

  ans = 2 * M_PI * i;

  printf("%f", ans);

  return 0;
}
