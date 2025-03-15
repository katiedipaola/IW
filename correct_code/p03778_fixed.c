#include <stdio.h>
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define abs(a) ((a) >= 0 ? (a) : -(a))

int main(void) {
  int W, a, b;
  scanf("%d %d %d", &W, &a, &b);
  printf("%d", max(abs(a - b) - W, 0));
  return 0;
}
