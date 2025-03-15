#include <stdio.h>
int a[100], b[100];
int main() {
  int n, i, j, s = 0, m = 0, t;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (j = 0; j < n; j++)
    scanf("%d", &b[j]);
  for (i = 0; i < n; i++) {
    s += a[i];
    t = s;
    for (j = i; j < n; j++)
      s += b[j];
    if (s > m)
      m = s;
    s = t;
  }
  printf("%d\n", m);
  return 0;
}
