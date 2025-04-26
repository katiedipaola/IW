#include <math.h>
#include <stdio.h>
int main(void) {
  int a, b, c, d, i;
  while (scanf("%d %d", &a, &b) != EOF) {
    c = a + b;
    for (i = 1; i < 6; i++) {
      d = pow(10, i);
      if (c < d) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}