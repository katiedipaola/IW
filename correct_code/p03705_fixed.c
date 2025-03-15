#include <stdio.h>
typedef long long ll;
int main() {
  ll n, a, b;
  scanf("%lld%lld%lld", &n, &a, &b);
  if (a > b) {
    printf("0\n");
    return 0;
  } else if (a == b) {
    printf("1\n");
    return 0;
  } else if (n == 1) {
    printf("0\n");
    return 0;
  }
  printf("%lld\n", a + (n - 1) * b - ((n - 1) * a + b) + 1);
  return 0;
}