#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d", &a, &b);
  if (a > b) {
    do {
      c = b;
      b = a % c;
      a = c;
    } while (b != 0);
  } else {
    do {
      c = a;
      a = b % c;
      b = c;
    } while (a != 0);
  }

  printf("%d\n", c);

  return 0;
}