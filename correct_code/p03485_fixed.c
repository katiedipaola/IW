#include <stdio.h>

int main() {
  double a, b;
  int x;
  scanf("%lf %lf", &a, &b);
  if ((a + b) / 2 - (int)((a + b) / 2) != 0.0)
    x = (a + b) / 2 + 1;
  else
    x = (a + b) / 2;
  printf("%d\n", x);
  return 0;
}
