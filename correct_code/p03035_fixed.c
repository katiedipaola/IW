#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a < 6) {
    printf("%d", 0);
  } else if (a > 12) {
    printf("%d", b);
  } else {
    printf("%d", b / 2);
  }
  return 0;
}