#include <stdio.h>
int main(void) {
  long long int n;
  scanf("%lld", &n);

  printf("%lld", n * (n - 1) / 2);

  return 0;
}
