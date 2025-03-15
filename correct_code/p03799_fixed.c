#include <stdio.h>

int main(void) {
  long long int N, M;
  scanf("%lld %lld", &N, &M);
  long long ans = 0;

  if (N * 2 >= M) {
    ans = M / 2;
  } else {
    ans = N;
    M -= N * 2;
    ans += M / 4;
  }

  printf("%lld\n", ans);

  return 0;
}