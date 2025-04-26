#include <stdio.h>
main() {
  int x, i = 1;
  while (1) {
    scanf("%d", &x);
    if (x == 0)
      break;
    printf("Case %d: %d", i, x);
    i = i + 1;
  }
  return 0;
}