#include <stdio.h>

int calc(int a, int c) {
  if (a == 4)
    return c + 4;

  c++;
  if (a % 2 == 0)
    calc(a / 2, c);
  else
    calc(a * 3 + 1, c);
}

int main() {
  int s;

  scanf("%d", &s);

  if (s == 1 || s == 2)
    printf("4");
  else
    printf("%d", calc(s, 0));

  return 0;
}