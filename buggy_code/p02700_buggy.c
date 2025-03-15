#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int A, B, C, D;
  scanf("%d %d %d %d", &A, &B, &C, &D);

  while (1) {
    A = A - B;
    if (A <= 0) {
      printf("Yes");
      break;
    }

    D = C - D;
    if (D <= 0) {
      printf("No");
      break;
    }
  }

  return 0;
}
