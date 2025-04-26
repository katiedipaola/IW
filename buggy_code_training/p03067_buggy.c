#include <stdio.h>

int main() {

  int A, B, C;

  scanf("%d %d %d", &A, &B, &C);

  if (B - A >= 1 && B > C) {
    printf("Yes");
  }

  else if (B - A <= 0 && (A > C && C > B)) {
    printf("Yes");
  }

  else
    printf("No");

  return 0;
}