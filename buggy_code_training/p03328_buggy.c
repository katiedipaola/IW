#include <stdio.h>

int main(void) {
  int a, b, i;

  scanf("%d %d", &a, &b);

  i = b - a;

  i = i * (i + 1) / 2;

  printf("%d\n", i - a);

  return 0;
}