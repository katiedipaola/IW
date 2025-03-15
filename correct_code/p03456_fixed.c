#include <math.h>
#include <stdio.h>
int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  if (b < 10) {
    a = 10 * a + b;
  } else if (10 <= b && b < 100) {
    a = 100 * a + b;
  } else {
    a = 1000 * a + b;
  }
  b = sqrt(a);
  // printf("%d\n",a);
  if ((b * b) == a) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
