#include <stdio.h>
int main(void) {
  int A, B, C, x;
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  x = B / A;
  if (x > C) {
    printf("%d", x);
  } else {
    printf("%d", C);
  }
  return 0;
}