#include <stdio.h>
int main(void) {
  int i, x, y;
  for (i = 1;; i++) {
    scanf("%d %d", x, y);
    if (x == 0 && y == 0)
      break;
    else if (x > y)
      printf("%d %d\n", y, x);
    else
      printf("%d %d\n", x, y);
  }
  return 0;
}