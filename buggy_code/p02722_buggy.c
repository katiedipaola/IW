#include <stdio.h>
long long f(long long n, long long k) { return n % k ? n % k : n / k; }
int main() {
  long long n, c = 0, i, j;
  scanf("%lld", &n);
  for (i = 1; i * i < n; i++) {
    if (n % i)
      continue;
    if (f(n, i) == 1)
      c++;
    if (f(n, n / i) == 1)
      c++;
  }
  if (i * i == n && f(n, i) == 1)
    c++;
  n--;
  // printf("%lld\n",n);
  for (i = 1; i * i < n; i++) {
    if (n % i == 0)
      c += 2;
  }
  if (i * i == n)
    c++;
  printf("%lld\n", c);
  return 0;
}
