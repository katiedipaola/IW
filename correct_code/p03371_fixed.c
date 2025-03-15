#include <stdio.h>
int max(long int a, long int b) {
  if (a > b)
    return a;
  else
    return b;
}

int min(long int a, long int b) {
  if (a > b)
    return b;
  else
    return a;
}

int main(void) {
  long int A, B, C, X, Y;
  scanf("%ld%ld%ld%ld%ld", &A, &B, &C, &X, &Y);

  int x = X, y = Y;
  long int cost2 = x * A + y * B;
  while (cost2 > cost2 + 2 * C - B - A && y - 1 >= 0 && x - 1 >= 0) {
    cost2 = cost2 + 2 * C - B - A;
    x--, y--;
  }

  long int a, b, c;
  c = 2 * min(X, Y);
  a = X - c / 2;
  b = Y - c / 2;
  long int cost = a * A + b * B + c * C;
  if (a == 0) {
    while (cost > cost + 2 * C - B && b - 1 >= 0) {
      cost = cost + 2 * C - B;
      b--;
    }
  }
  if (b == 0) {
    while (cost > cost + 2 * C - A && a - 1 >= 0) {
      cost = cost + 2 * C - A;
      a--;
    }
  }

  if (cost < cost2)
    printf("%ld", cost);
  else
    printf("%ld", cost2);

  return 0;
}
