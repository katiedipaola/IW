#include <stdio.h>
int main() {
  int a, n, i, j, total = 0, high = -100001, nam[5000];
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    for (j = 0; j < n; j++) {
      scanf("%d", &nam[j]);
    }
    high = nam[0];
    for (i = 0; i < n - 1; i++) {
      total = 0;
      for (j = i; j < n; j++) {
        total += nam[j];
        if (total > high) {
          high = total;
        }
      }
    }

    printf("%d\n", high);
    high = 0;
    total = 0;
  }
  return 0;
}