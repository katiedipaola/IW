#include <stdio.h>
int main() {
  int n, m, p[1000], i, j, sum, k;
  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0)
      break;

    for (i = 0; i < n; i++)
      scanf("%d", &p[i]);

    for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
        if (p[j] < p[j + 1]) {
          k = p[j];
          p[j] = p[j + 1];
          p[j + 1] = k;
        }
      }
    }

    for (i = 0; i < n; i++) {
      if ((i + 1) % m == 0) {
        p[i] = 0;
      }
    }

    sum = 0;

    for (i = 0; i < n; i++) {
      sum += p[i];
    }

    printf("%d\n", sum);
  }
  return 0;
}