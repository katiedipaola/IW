#include <stdio.h>

int gcd(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }

  return b;
}

int main(void) {
  int i;
  int n;
  int x, x_next;
  int dx;
  int d;

  scanf("%d%d", &n, &x);
  scanf("%d", &x_next);
  dx = x_next - x;
  if (dx < 0)
    dx = -dx;
  x = x_next;
  d = dx;
  for (i = 2; i < n; i++) {
    scanf("%d", &x_next);
    dx = x_next - x;
    if (dx < 0)
      dx = -dx;
    x = x_next;
    d = gcd(d, dx);
  }

  printf("%d\n", d);

  return 0;
}
