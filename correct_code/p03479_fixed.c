#include <stdio.h>

int main(void) {
  int i = 1, c = 0;
  long long a, b;
  scanf("%lld %lld", &a, &b);
  while (i) {
    if (a <= b) {
      c = c + 1;
    }
    if (a > b) {
      i = 0;
    }
    a = a * 2;
  }
  printf("%d", c);
  return 0;
}