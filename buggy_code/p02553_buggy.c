#include <limits.h>
#include <stdio.h>
int main() {
  long a, b, c, d;
  scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
  long long p, q, r, s;
  p = b * d;
  q = a * c;
  r = a * d;
  s = b * c;
  long long max = LLONG_MIN;

  // printf("%ld %ld %ld %ld\n", p, q, r, s);
  max = (max > p) ? max : p;
  max = (max > p) ? max : q;
  max = (max > p) ? max : r;
  max = (max > p) ? max : s;

  printf("%lld", max);
  return 0;
}