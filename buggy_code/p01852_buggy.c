#include <stdio.h>
int main() {
  long long N;
  scanf("%lld", &N);
  printf("%d\n", N ? 0 : 64 - __builtin_clzll(N));
  return 0;
}