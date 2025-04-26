#include <stdio.h>
int main(void) {
  int a, b, c = 0, d = 1;
  scanf("%d", &a);
  scanf("%d", &b);
  for (;;) {
    if (b <= d) {
      break;
    } else {
      d = d + a;
      c++;
    }
  }
  printf("%d", c);
  return 0;
}