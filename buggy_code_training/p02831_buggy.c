#include <stdio.h>
int main() {
  int A, B, X, Y, Num_snack;
  scanf("%d%d", &A, &B);
  if (A > B) {
    X = A;
  } else {
    X = B;
  }
  for (; X >= 1; X--) {
    if (A % X == 0 && B % X == 0) {
      Y = X;
      break;
    }
  }
  Num_snack = (A * B) / Y;
  printf("%d\n", Num_snack);
  return 0;
}
