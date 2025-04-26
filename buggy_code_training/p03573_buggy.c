#include <stdio.h>

int main(void) {
  int A, B, C;
  scanf("%d %d %d", &A, &B, &C);
  if (A == B) {
    printf("%d\n", C);
  } else if (A == C) {
    printf("%d\n", C);
  } else if (B == C) {
    printf("%d\n", A);
  }
  return 0;
}
