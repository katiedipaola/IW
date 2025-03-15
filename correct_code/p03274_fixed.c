#include <stdio.h>
#include <stdlib.h>
long long MIN(long long a, long long b) {
  return labs(a) < labs(b) ? labs(a) : labs(b);
}
int main() {
  int n, m, i;
  long long s = 1e18, d[100010];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    scanf("%lld", &d[i]);
  for (i = m - 1; i < n; i++)
    s = MIN(s, d[i] - d[i - m + 1] + MIN(d[i], d[i - m + 1]));
  printf("%lld\n", s);
  return 0;
}
