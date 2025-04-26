#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a < 6) {
    printf("0");
  } else if (b > 12) {
    printf("%d", b);
  } else {
    printf("%d", b / 2);
  }
  return 0;
}