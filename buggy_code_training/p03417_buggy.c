#include <stdio.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a == 1 && b == 1) {
    printf("1");
  } else if (a == 1 || b == 1) {
    printf("%d", a * b - 2);
  } else {
    printf("%d", (a - 2) * (b - 2));
  }
}