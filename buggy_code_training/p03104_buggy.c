#include <stdio.h>
int main() {
  long long int a, b, i, ans;
  scanf("%lld%lld", &a, &b);
  if (a % 2 == 0 && b % 2 == 1)
    ans = ((b - a) / 2) % 2;
  else if (a % 2 == 0 && b % 2 == 0) {
    i = ((b - a) / 2) % 2;
    ans = i ^ b;
  } else if (a % 2 == 1 && b % 2 == 1) {
    i = ((b - a + 2) / 2) % 2;
    ans = i ^ a;
  } else {
    i = ((b - a + 1) / 2 % 2);
    ans = a ^ i;
    ans = ans ^ b;
  }
  printf("%lld", ans);
}