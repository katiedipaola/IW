#include <stdio.h>
int main(void) {
  int n, m, h[100001], a[100001], b[100001], i, j, c[100001], d[100001], e;
  e = 0;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a[i], &b[i]);
    /*printf("%d %d\n",a[i],b[i]);*/
  }
  for (i = 1; i <= n; i++) {
    c[i] = 1;
    d[i] = 0;
  }
  for (i = 0; i < m; i++) {
    if (h[a[i] - 1] > h[b[i] - 1]) {
      c[a[i]] = 1;
      d[b[i]] = 1;
    } else if (h[a[i] - 1] < h[b[i] - 1]) {
      c[b[i]] = 1;
      d[a[i]] = 1;
    }
    /*printf("%d\n",d[4]);*/
  }
  for (i = 1; i <= n; i++) {
    /*printf("%d\n",d[i]);*/
    if (d[i] == 0) {
      e++;
    }
  }
  printf("%d\n", e);
  return 0;
}
