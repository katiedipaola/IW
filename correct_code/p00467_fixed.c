#include <stdio.h>

int main() {
  int n, m, i, c, count, a[1000], b[1000], start;

  while (1) {
    start = 1;
    count = 0;
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (i = 0; i < m; i++) {
      scanf("%d", &b[i]);
    }
    for (i = 0; i < m; i++) {
      c = start + b[i];
      start += b[i] + a[c - 1];
      count++;
      if (start >= n)
        break;
    }
    printf("%d\n", count);
  }

  return 0;
}