#include <stdio.h>
#define S_MAX 1000

int main(void) {
  int sum, min, max, n, t, i;

  while (scanf("%d", &n), n != 0) {
    sum = min = 0, max = S_MAX;

    for (i = 0; i < n; i++) {
      scanf("%d", &t);

      if (min > t)
        min = t;
      if (max < t)
        max = t;

      sum += t;
    }

    printf("%d\n", (sum - min - max) / (n - 2));
  }

  return 0;
}