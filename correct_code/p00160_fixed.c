#include <stdio.h>

int main(void) {
  int size_limit[6] = {60, 80, 100, 120, 140, 160};
  int weight_limit[6] = {2, 5, 10, 15, 20, 25};
  int fee[6] = {600, 800, 1000, 1200, 1400, 1600};

  int n;
  int x, y, h, w;
  int size;
  int sum;
  int i, j;

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    sum = 0;

    for (i = 0; i < n; i++) {
      scanf("%d %d %d %d", &x, &y, &h, &w);
      size = x + y + h;

      for (j = 0; j < 6; j++) {
        if (size <= size_limit[j] && w <= weight_limit[j]) {
          break;
        }
      }

      if (j < 6) {
        sum += fee[j];
      }
    }

    printf("%d\n", sum);
  }

  return (0);
}