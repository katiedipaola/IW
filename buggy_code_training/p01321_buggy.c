#include <stdio.h>
int main() {
  int a, b, c, d, e, n, total, score, max, min, i;
  max = 0;
  min = 500;
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (i = 0; i < n; i++) {
      scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
      total = a + b + c + d + e;
      if (total > max) {
        max = total;
      }
      if (total < min) {
        min = total;
      }
    }
    printf("%d %d\n", max, min);
  }
  max = 0;
  min = 500;
  return 0;
}