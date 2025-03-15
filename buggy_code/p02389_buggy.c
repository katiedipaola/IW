#include <stdio.h>

int main(void) {
  int a, b;
  int x, y;
  scanf("%d %d", &a, &b);
  x = a * b;
  y = 2 * (a + b);
  printf("%d\n %d\n", x, y);

  return 0;
}
