#include <stdio.h>
int main() {
  int n, y, i, j, b, r, t, num;
  double ans, max;

  while (1) {

    max = 0.0;

    scanf("%d", &n);
    if (n == 0)
      break;

    scanf("%d", &y);

    for (i = 0; i < n; i++) {
      scanf("%d%d%d", &b, &r, &t);

      if (t == 1) {
        ans = (1 + y * (double)r / 100);

      }

      else {
        for (j = 0; j < y; j++) {
          ans *= (1 + (double)r / 100);
        }
      }

      if (max < ans) {
        num = b;
        max = ans;
      }
    }

    printf("%d\n", num);
  }

  return 0;
}