#include <stdio.h>
int main() {
  int a[30];
  int i, n, m;
  int tmp, x, y;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d, %d", &x, &y);
    tmp = a[x - 1];
    a[x - 1] = a[y - 1];
    a[y - 1] = tmp;
  }
  for (i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
  return 0;
}