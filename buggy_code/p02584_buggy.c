#include <stdio.h>
long long MIN(long long a, long long b) { return a < b ? a : b; }
int main() {
  long long n, m, d;
  scanf("%lld %lld %lld", &n, &m, &d);
  if (n < 0)
    n = -n;
  if (n / m > d) {
    printf("%lld\n", n - (m * d));
    return 0;
  }
  m -= n / d;
  n %= d; // printf("%lld %lld\n",d,n);
  printf("%lld\n", m % 2 ? d - n : n);
  return 0;
}
