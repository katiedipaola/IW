#include <stdio.h>
int main() {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  if (a + b < c) {
    printf("no");
  } else {
    printf("yes");
  }
  return 0;
}