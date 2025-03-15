#include <stdio.h>
int main() {
  int x, i = 1;
  scanf("%d", &x);
  for (; i * (i + 1) < x; i++)
    ;
  printf("%d", i + 1);
}