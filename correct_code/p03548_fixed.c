#include <stdio.h>

int main(void) {
  int x, y, z, count;
  scanf("%d %d %d\n", &x, &y, &z);
  count = 0;
  x -= z;
  while (x >= (y + z)) {
    count++;
    x -= (y + z);
  }
  printf("%d\n", count);
  return 0;
}
