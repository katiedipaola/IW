#include <stdio.h>

int main(void) {
  int x;
  int a;
  int b;
  int n;
  int c;

  scanf("%d", &x);

  a = 2;
  b = 2;
  c = 2;
  n = 0;
  while (a * a <= x) {
    a = c;
    b = c;
    while (b * b <= x) {
      b = b * a;
      if (n < b) {
        n = b;
      }
    }
    c++;
  }
  if (x <= 3) {
    n = 1;
  }

  printf("%d\n", n);

  return (0);
}