#include <stdio.h>
int main(void) {
  int i, j, n, k, t, d[100], a[100], s = 0;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    a[i] = 0;
  }
  for (i = 1; i <= k; i++) {
    scanf("%d", &d[i]);
    for (j = 1; j <= d[i]; j++) {
      scanf("%d", &t);
      a[t] = 1;
    }
  }
  for (i = 1; i <= n; i++) {
    if (a[i] = 0) {
      s++;
    }
  }
  printf("%d", s);
  return 0;
}
