#include <math.h>
#include <stdio.h>

int main() {
  int i, j, n, m, total;
  while (1) {
    total = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    m = n;
    for (i = 2; i < sqrt(n); i++) {
      if (n % i == 0) {
        if (i == n / i) {
          total += i;
          continue;
        }
        total = total + i + n / i;
      }
    }
    if (total)
      total++;
    if (total == m) {
      printf("perfect number\n");
    } else if (total > m) {
      printf("abundant number\n");
    } else if (total < m) {
      printf("deficient number\n");
    }
  }
  return 0;
}