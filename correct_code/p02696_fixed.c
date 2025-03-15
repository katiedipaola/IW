#include <stdio.h>
#include <stdlib.h>

int main(void) {
  long long int a, b, n, ans, x;
  scanf("%lld %lld %lld", &a, &b, &n);
  if (b <= n) {
    x = b - 1;
  } else {
    x = n;
  }
  ans = a * x / b;
  printf("%lld\n", ans);
  return 0;
}
