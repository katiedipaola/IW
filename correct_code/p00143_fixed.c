#include <stdio.h>
int main() {
  int x[5], y[5], n, ax, ay, bx, by, i, j;
  scanf("%d", &n);
  while (n--) {
    for (i = 0; i < 5; i++)
      scanf("%d %d", &x[i], &y[i]);
    int f[2] = {0};
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        ax = x[(j + 1) % 3] - x[j];
        ay = y[(j + 1) % 3] - y[j];
        bx = x[i + 3] - x[j];
        by = y[i + 3] - y[j];
        if (ax * by > ay * bx)
          f[i]++;
      }
      f[i] %= 3;
    }
    if (f[0] + f[1] == 0 || f[0] * f[1])
      printf("NG\n");
    else
      printf("OK\n");
  }
  return 0;
}