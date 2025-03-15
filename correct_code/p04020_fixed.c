#include <stdio.h>
int main() {
  long long n, a, b = 0, s = 0;
  scanf("%lld", &n);
  while (n--) {
    scanf("%lld", &a);
    b += a;
    s += b / 2;
    b = a ? b % 2 : 0;
  }
  printf("%lld\n", s);
  return 0;
}
