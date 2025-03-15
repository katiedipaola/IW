#include <stdio.h>

int main(void) {
  int a, b, i;

  a = 0;
  b = 0;

  for (i = 0; i < 10; i++) {
    scanf("%d", &a);

    b = a + b;
  }

  printf("%d\n", b);

  return 0;
}