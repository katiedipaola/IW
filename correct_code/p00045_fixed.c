#include <stdio.h>

int main(void) {
  int a, b, s, r, n;
  char c;
  s = r = n = 0;
  while (scanf("%d%c%d\n", &a, &c, &b) == 3) {
    s = s + a * b;
    r = r + b;
    n++;
  }

  printf("%d\n%d\n", s, (int)((0.0 + r) / n + 0.5));

  return 0;
}