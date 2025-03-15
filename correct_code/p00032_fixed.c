#include <stdio.h>

int main() {
  int a, b, c, t = 0, h = 0;

  while (scanf("%d,%d,%d", &a, &b, &c) != EOF) {
    if (a + b <= c)
      continue;
    else if (a * a + b * b == c * c)
      t++;
    else if (a == b)
      h++;
  }

  printf("%d\n%d\n", t, h);
  return 0;
}