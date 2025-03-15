#include <stdio.h>

int main(void) {
  int a, b, c, n, t, S = 0, A = 0, C = 0, D = 0;

  for (S = 0;;) {
    scanf("%d %d %d\n", &a, &b, &c);
    if (a < b) {
      t = a;
      a = b;
      b = t;
    }
    if (a < c) {
      t = a;
      a = c;
      c = t;
    }
    if (a >= b + c)
      break;
    S++;
    if (a * a < b * b + c * c)
      A++;
    else if (a * a == b * b + c * c)
      C++;
    else if (a * a > b * b + c * c)
      D++;
  }
  printf("%d %d %d %d\n", S, C, A, D);
}
