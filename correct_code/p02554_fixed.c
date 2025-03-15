#include <stdio.h>

int main() {
  int n, i;
  scanf("%d", &n);
  long long int x10 = 1, x9 = 1, x8 = 1;
  for (i = 0; i < n; i++) {
    x10 = (10 * x10) % 1000000007;
    x9 = (9 * x9) % 1000000007;
    x8 = (8 * x8) % 1000000007;
  }
  printf("%lld", (x10 - 2 * x9 + x8 + 2 * 1000000007) % 1000000007);
  return 0;
}