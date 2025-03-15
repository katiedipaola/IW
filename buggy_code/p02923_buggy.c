#include <stdio.h>
int main() {
  int n, a, b, m = 0, c = 0, i;
  scanf("%d %d", &n, &b);
  for (i = 1; i < n; i++) {
    scanf("%d", &a);
    if (b >= a)
      c++;
    else
      c = 0;
    if (c > m)
      m = c;
    b = a;
  }
  if (c < m)
    m = c;
  printf("%d\n", m);
  return 0;
}
