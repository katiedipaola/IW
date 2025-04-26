#include <stdio.h>

int main() {
  int a, b, n;
  int x, i;
  int sum;

  while (scanf("%d %d %d", &a, &b, &n) != EOF) {
    sum = 0;
    if (a > b)
      a = a % b;

    for (i = 0; i < n; i++) {
      a = a * 10;
      sum += a / b;
      a = a % b;
      if (a == 0)
        break;
    }

    printf("%d\n", sum);
  }

  return 0;
}
