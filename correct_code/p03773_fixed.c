#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, A, B;
  scanf("%d %d", &A, &B);
  if ((A + B) >= 24) {
    printf("%d\n", (A + B - 24));
  } else {
    printf("%d\n", A + B);
  }
  return 0;
}