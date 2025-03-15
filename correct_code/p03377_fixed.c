#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void change(int *x, int *y);

int a, b, x;

int main(void) {
  scanf("%d %d %d", &a, &b, &x);

  if (x >= a && x <= a + b)
    printf("YES");
  else
    printf("NO");

  return 0;
}

void change(int *x, int *y) {
  int z;
  z = *x;
  *x = *y;
  *y = z;
}