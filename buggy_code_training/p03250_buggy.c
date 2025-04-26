#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a, b, c, max;

  scanf("%d %d %d", &a, &b, &c);

  if (a >= b)
    max = a;
  if (c >= max)
    max = c;

  printf("%d", a + b + c + 9 * max);

  return 0;
}