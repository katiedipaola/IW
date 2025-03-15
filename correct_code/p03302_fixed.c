#include <stdio.h>
int main(void) {
  int a = 0, b = 0;

  scanf("%d %d", &a, &b);

  if (a + b == 15) {
    printf("+\n");
  } else if (a * b == 15) {
    printf("*\n");
  } else {
    printf("x\n");
  }

  return 0;
}
