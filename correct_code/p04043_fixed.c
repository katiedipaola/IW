#include "stdio.h"

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  int c1 = 0, c2 = 0;

  if (a == 5)
    c1++;
  else if (a == 7)
    c2++;

  if (b == 5)
    c1++;
  else if (b == 7)
    c2++;

  if (c == 5)
    c1++;
  else if (c == 7)
    c2++;

  if (c1 == 2 && c2 == 1)
    printf("YES\n");
  else
    printf("NO\n");
}
