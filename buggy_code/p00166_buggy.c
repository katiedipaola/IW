#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int n, i;
double ang, deg, a[2];

int main() {
  while (1) {
    for (i = 0; i < 2; i++) {
      scanf("%d", &n);
      if (n == 0)
        break;
      a[i] = 0;
      for (ang = 360; n > 1; n--) {
        scanf("%lf", &deg);
        ang -= deg;
        deg = deg / 180 * 3.1415926535897932384626433832795;
        a[i] += cos(deg / 2) * sin(deg / 2);
      }
      ang = ang / 180 * 3.1415926535897932384626433832795;
      a[i] += cos(ang / 2) * sin(ang / 2);
    }
    if (i == 0)
      break;
    if (a[0] > a[1])
      printf("--1\n");
    else if (a[0] < a[1])
      printf("--2\n");
    else
      printf("--0\n");
  }
  return 0;
}