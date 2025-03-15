#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void) {
  int a, b, c;
  int tmp;
  int x;

  scanf("%d %d %d", &a, &b, &c);

  if (c > a && c > b) {
    tmp = c;
    c = a;
    a = tmp;
  }

  if (b > a && b > c) {
    tmp = b;
    b = a;
    a = tmp;
  }

  x = (a - b) + (a - c);

  if (x % 2 == 0)
    printf("%d\n", x / 2);
  else
    printf("%d\n", x / 2 + 1);

  return 0;
}