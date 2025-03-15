#include <stdio.h>

int main(void) {
  int A, B;

  scanf("%d %d", &A, &B);

  if (A * B % 2 == 0) {
    printf("No");
  } else {
    printf("Yes");
  }

  return 0;
}
