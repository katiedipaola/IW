#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int a;
  scanf("%4d", &a);
  if (a % 2 == 0)
    printf("%d", a);
  else
    printf("%d", a * 2);

  return 0;
}