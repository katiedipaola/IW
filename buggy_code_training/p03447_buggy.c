#include <stdio.h>
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int d;
  d = a - b;

  printf("%d", d % b);

  return 0;
}