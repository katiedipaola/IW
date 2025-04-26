#include <math.h>
#include <stdio.h>

int input(int *x, int *h);
int main() {
  int x, h;
  double l, s;
  while (input(&x, &h) == 0) {
    l = sqrt((double)x * x / 4 + h * h);
    s = l * x * 2 + x * x;
    printf("%lf", s);
  }
  return 0;
}

int input(int *x, int *h) {
  scanf("%d", x);
  scanf("%d", h);
  if (*x == 0 && *h == 0) {
    return 1;
  } else {
    return 0;
  }
}