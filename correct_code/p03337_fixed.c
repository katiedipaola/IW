#include <stdio.h>

int main() {

  int A, B;
  int Add, Sub, Mul;
  int Result;

  scanf("%d %d", &A, &B);

  Add = A + B;
  Sub = A - B;
  Mul = A * B;

  if (Add >= Sub && Add >= Mul) {
    Result = Add;
  } else if (Sub >= Add && Sub >= Mul) {
    Result = Sub;
  } else {
    Result = Mul;
  }

  printf("%d", Result);

  return 0;
}
