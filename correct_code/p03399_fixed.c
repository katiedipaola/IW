#include <stdio.h>

int main(void) {
  int A, B, C, D, train, bus, fee;
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &D);

  train = (A < B) ? A : B;
  bus = (C < D) ? C : D;

  fee = train + bus;
  printf("%d\n", fee);

  return 0;
}