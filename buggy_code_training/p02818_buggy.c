#include <stdio.h>
int main() {
  long long int a, b, c, i, n;
  scanf("%lld%lld%lld", &a, &b, &c);
  if (a > c)
    printf("%lld %lld\n", a - c, b);
  else if (b > c - a)
    printf("0 %lld\n", c - (b - a));
  else if (a + b <= c)
    printf("0 0");
}
