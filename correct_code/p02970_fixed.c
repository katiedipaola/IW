#include <stdio.h>
int main(void) {
  int r, a, b;

  scanf("%d %d", &r, &a);
  b = r / (a * 2.0 + 1.0) + 0.99999;
  printf("%d\n", b);
  return 0;
}