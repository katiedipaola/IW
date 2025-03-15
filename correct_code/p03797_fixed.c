#include <stdio.h>

int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);

  if (2 * n < m)
    printf("%lld\n", (2 * n + m) / 4);
  else
    printf("%lld\n", m / 2);

  return 0;
}