#include <stdio.h>

int main(void) {
  int m, t;
  scanf("%d", &m);
  t = m % 1000;
  printf("%d", (1000 - t) % 1000);
  return 0;
}