#include <stdio.h>
int main() {
  long long int a, b, i, d, e, f;
  long long int c = 0;
  scanf("%lld %lld", &a, &b);
  f = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;
  for (i = b; i < a + 2; ++i) {
    d = (i - 1) * i / 2;
    e = i * (2 * a + 1 - i) / 2;
    c = c + e - d + 1;
  }
  printf("%lld", c % f);
  return 0;
}