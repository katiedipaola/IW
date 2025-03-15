#include <stdio.h>

int main(void) {
  int i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    int y, m, d, total = 0;
    scanf("%d %d %d", &y, &m, &d);
    if (y % 3 == 0) {
      total += (999 - y) / 3 * 590;
      total += (10 - m) * 20;
      total += 21 - d;
    } else if (y % 3 == 1) {
      total += (997 - y) / 3 * 590 + 395;
      if (m % 2 == 1) {
        total += 19 + (9 - m) / 2 * 39;
        total += 21 - d;
      } else if (m % 2 == 0) {
        total += (10 - m) / 2 * 39;
        total += 20 - d;
      }
    } else if (y % 3 == 2) {
      total += (998 - y) / 3 * 590 + 200;
      if (m % 2 == 1) {
        total += 19 + (9 - m) / 2 * 39;
        total += 21 - d;
      } else if (m % 2 == 0) {
        total += (10 - m) / 2 * 39;
        total += 20 - d;
      }
    }
    printf("%d\n", total);
  }
  return 0;
}