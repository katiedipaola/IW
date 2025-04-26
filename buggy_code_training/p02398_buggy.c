#include <stdio.h>

int main() {

  int a, b, c, count = 0, i, t;

  scanf("%d %d %d", &a, &b, &c);

  for (i = a; i < (b + 1); i++) {
    t = c / i;
    if (t == 0)
      count++;
  }

  printf("%d\n", count);

  return 0;
}