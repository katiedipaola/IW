#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a < b ? a : b)

int main() {
  int i, n, k, h[100010];
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }

  int j, x, cost[100010] = {0, abs(h[0] - h[1])};

  for (i = 2; i < n; i++) {
    x = cost[i - 1] + abs(h[i] - h[i - 1]);
    for (j = 1; j < min(k, i); j++) {
      x = min(x, cost[i - 1 - j] + abs(h[i] - h[i - 1 - j]));
    }
    cost[i] = x;
  }

  printf("%d", cost[n - 1]);
}
