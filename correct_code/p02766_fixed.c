#include <stdio.h>

int main(void) {
  long long int N, K_tmp = 1;
  int i = 0, K;

  scanf("%lld %d", &N, &K);

  if (K_tmp > N) {
    i = 1;
  }
  while (K_tmp <= N) {
    K_tmp *= K;
    i++;
  }

  printf("%d\n", i);

  return 0;
}