#include <stdio.h>

int max(int a, int b);

int main(void) {
  int a, b, sum = 0, k = 0;
  scanf("%d%d", &a, &b);
  k = max(a, b);

  sum = sum + k;

  if (k == a)
    a = a - 1;
  else if (k == b)
    b = b - 1;

  sum = sum + max(a, b);
  printf("%d", sum);
  return 0;
}

int max(int a, int b) {
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}