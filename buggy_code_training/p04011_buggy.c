#include <stdio.h>

int main(void) {
  int N, K, X, Y;
  int pay;
  scanf("%d %d %d %d", &N, &K, &X, &Y);
  if (K < N) {
    pay = K * X + (N - K) * Y;
  } else {
    pay = N * K;
  }
  printf("%d", pay);
  return 0;
}