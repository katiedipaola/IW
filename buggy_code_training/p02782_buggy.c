#include <stdio.h>
long long int fact[2000006];
long long int inv[2000006];
long long int modpow(long long int a, long long int n, long long int p) {
  if (n < 0)
    return 0;
  long long int res = 1;
  while (n > 0) {
    if (n % 2 > 0)
      res = res * a % p;
    a = a * a % p;
    n /= 2;
  }
  return res;
}
long long int g(long long int r, long long int c, long long int p) {
  long long int i;
  long long int res = 0;
  for (i = 0; i <= r; i++)
    res = (res + fact[i + c + 1] * inv[i + 1] % p) % p;
  return res * inv[c] % p;
}
int main() {
  long long int r1, r2, c1, c2;
  scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
  long long int p = 1000000007;
  long long int i;
  fact[0] = 1;
  for (i = 1; i < 2000006; i++)
    fact[i] = fact[i - 1] * i % p;
  for (i = 0; i < 2000006; i++)
    inv[i] = modpow(fact[i], p - 2, p);
  printf("%lld\n", (g(r2, c2, p) - g(r2, c1 - 1, p) - g(r1 - 1, c2, p) +
                    g(r1 - 1, c1 - 1, p)) %
                       p);
  return 0;
}