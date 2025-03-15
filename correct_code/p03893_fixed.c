#include <stdio.h>
#include <stdlib.h>
long long g(long long int n) {
  if (n == 0) {
    return 2;
  } else {
    return g(n - 1) * 2 + 2;
  }
}
int main() {
  long long n, k;
  scanf("%lld", &n);
  k = g(n);
  printf("%lld", k);
  return 0;
}