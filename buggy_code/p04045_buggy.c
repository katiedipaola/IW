#include <stdio.h>
int main(void) {
  int n, k, i, j, x, f, d[10] = {0};
  scanf("%d %d", &n, &k);
  while (k--) {
    scanf("%d", &x);
    d[x] = 1;
  }
  for (i = n; i < 10000; i++) {
    x = i;
    f = 0;
    while (x) {
      if (d[x % 10]) {
        f = 1;
        break;
      }
      x /= 10;
    }
    if (f)
      continue;
    else
      break;
  }
  printf("%d\n", i);
  return 0;
}
