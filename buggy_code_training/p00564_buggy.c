#include <stdio.h>

int main(void) {
  int N, A, B, C, D, price_X, price_Y, mod;
  scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
  if (N % A != 0) {
    mod = 1;
  } else {
    mod = 0;
  }
  price_X = (N / A + mod) * B;
  if (N % B != 0) {
    mod = 1;
  } else {
    mod = 0;
  }
  price_Y = (N / C + mod) * D;
  if (price_X < price_Y) {
    printf("%d\n", price_X);
  } else {
    printf("%d\n", price_Y);
  }
  return 0;
}
