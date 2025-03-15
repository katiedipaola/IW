#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  long long x[n], y[m], sum = 0, prev = 0, ans = 0, mod = 1000000007;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x[i]);
    if (i > 0) {
      prev = (prev + i * llabs(x[i] - x[i - 1])) % mod;
      sum = (sum + prev) % mod;
    }
  }
  prev = 0;
  for (int i = 0; i < m; i++) {
    scanf("%lld", &y[i]);
    if (i > 0) {
      prev = (prev + i * llabs(y[i] - y[i - 1])) % mod;
      ans = (ans + (sum * prev) % mod) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
