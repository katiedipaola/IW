#include <stdio.h>
int main() {
  int a, b, e, n;
  int c[301], i, d[100], m[100], k[100], r[100];
  while (1) {
    scanf("%d %d %d", &a, &b, &e);
    if (!(a || b || e))
      break;
    scanf("%d", &n);
    for (i = 1; i <= a + b + e; i++)
      c[i] = 2;
    for (i = 0; i < n; i++) {
      scanf("%d %d %d %d", &d[i], &m[i], &k[i], &r[i]);
      if (r[i]) {
        c[d[i]] = 1;
        c[m[i]] = 1;
        c[k[i]] = 1;
      }
    }
    for (i = 0; i < n; i++) {
      if (r[i])
        continue;
      if (c[d[i]] * c[m[i]] * c[k[i]] == 2) {
        if (c[d[i]] == 2)
          c[d[i]] = 0;
        if (c[m[i]] == 2)
          c[m[i]] = 0;
        if (c[k[i]] == 2)
          c[k[i]] = 0;
      }
    }
    for (i = 1; i <= a + b + e; i++)
      printf("%d\n", c[i]);
  }
  return 0;
}