#include <stdio.h>
#define mod (int)(1e9 + 7)

long long int MOD(long long int a) {
  if (a < 0) {
    mod + a % mod;
  } else {
    return a % mod;
  }
}

int main() {
  int m, n, i;
  long long int x, y, sumn = 0, summ = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &x);
    sumn = MOD(sumn + ((2 * i - 1 - n) * x));
  }
  for (i = 1; i <= m; i++) {
    scanf("%lld", &y);
    summ = MOD(summ + ((2 * i - 1 - m) * y));
  }
  printf("%d\n", (sumn * summ) % mod);
  return 0;
}