#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, m, i, j, min, sum, sum1, sum2, d;
  int ansa, ansb;
  int a[100];
  int b[100];

  while (scanf("%d%d", &n, &m), n + m) {

    sum = 0;
    sum1 = 0;
    sum2 = 0;
    min = 200;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum1 += a[i];
    }
    for (i = 0; i < m; i++) {
      scanf("%d", &b[i]);
      sum2 += b[i];
    }

    sum = sum1 + sum2;

    if (sum % 2) {
      printf("-1\n");
    } else {
      d = abs(sum1 - sum2) / 2;
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          if (d == (sum1 > sum2 ? a[i] - b[j] : b[j] - a[i])) {
            if (min > a[i] + b[j]) {
              ansa = a[i];
              ansb = b[j];
              min = a[i] + b[j];
            }
          }
        }
      }
      if (min == 200)
        printf("-1\n");
      else
        printf("%d %d\n", ansa, ansb);
    }
  }
  return 0;
}