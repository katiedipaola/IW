#include <stdio.h>

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  int a;
  a = n * 3 + p;
  a = a / 3;

  printf("%d", a);
  return 0;
}