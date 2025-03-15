#include <stdio.h>
int main() {
  int n, x, m, min = 1000, ans;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    x -= m;
    if (min > m)
      min = m;
  }
  ans = 3 + x / min;
  printf("%d", ans);
  return 0;
}