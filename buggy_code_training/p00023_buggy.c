#include <math.h>
#include <stdio.h>

int main(void) {
  int n;
  double xa, ya, ra, xb, yb, rb;
  double dist;

  scanf("%d", &n);
  for (; n > 0; n--)
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
  dist = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
  if (dist > ra + rb) {
    printf("%d\n", 0);
  } else if (dist < ra - rb) {
    printf("%d\n", 2);
  } else if (dist < rb - ra) {
    printf("%d\n", -2);
  } else {
    printf("%d\n", 1);
  }

  return 0;
}