#include <stdio.h>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if ((a - b) < 0)
    puts("0");
  printf("%d", a - b);

  return 0;
}