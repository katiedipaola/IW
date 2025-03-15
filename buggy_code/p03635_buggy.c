#include <stdio.h>

int main() {
  int a;
  int b;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a > 1 && a < 101) {
    if (b > 2 && b < 101) {
      a--;
      b--;
      int c = a * b;
      printf("%d\n", c);
    }
  }
  return 0;
}
