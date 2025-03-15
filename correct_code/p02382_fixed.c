#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, n, x[100], y[100];
  double p_1 = 0, p_2 = 0, p_3 = 0, p_0 = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);
  for (i = 0; i < n; i++)
    scanf("%d", &y[i]);

  for (i = 0; i < n; i++) {

    // p=1
    p_1 += abs(x[i] - y[i]);

    // p=2
    p_2 += pow(fabs((double)x[i] - y[i]), 2.0);

    // p=3
    p_3 += pow(fabs((double)x[i] - y[i]), 3.0);

    // p=endless
    if (p_0 < abs(x[i] - y[i]))
      p_0 = abs(x[i] - y[i]);
  }

  printf("%lf\n%lf\n%lf\n%lf\n", p_1, pow(p_2, 1.0 / 2), pow(p_3, 1.0 / 3),
         p_0);

  return 0;
}