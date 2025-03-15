#include <stdio.h>

int main() {
  int m, n, a[1001], i, j, sum, max;

  while (scanf("%d %d", &n, &m)) {
    if (m == 0 && n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    max = 0;
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        sum = a[i] + a[j];
        if (sum <= m)
          max = sum;
      }
    }
    if (max == 0)
      printf("NONE\n");
    else
      printf("%d\n", max);
  }
  return 0;
}
