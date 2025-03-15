#include <math.h>
#include <stdio.h>
int main(void) {

  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);

  if (A - B > C) {
    printf("%d", 0);
  } else if (A - B < C) {
    printf("%d", C - A + B);
  }

  return 0;
}