#include <stdio.h>

int main() {
  int sum = 0, l[10], v1, v2, i;
  double t, r;

  while (scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", l, l + 1, l + 2, l + 3,
               l + 4, l + 5, l + 6, l + 7, l + 8, l + 9, &v1, &v2) != EOF) {
    for (i = 0; i < 10; i++)
      sum += l[i];
    t = (double)sum / (v1 + v2);
    r = v1 * t;

    for (i = 0; i < 10; i++) {
      r -= l[i];
      if (r <= 0.0) {
        printf("%d\n", i + 1);
        break;
      }
    }
    sum = 0;
  }

  return 0;
}