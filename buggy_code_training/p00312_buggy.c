#include <stdio.h>

int main(void) {
  int times, dist, len;

  scanf("%d %d", &dist, &len);

  times = dist / len;
  times = dist % len;

  printf("%d\n", times);

  return 0;
}