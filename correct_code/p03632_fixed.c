#include <stdio.h>

int main(void) {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (b <= c || d <= a)
    printf("%d", 0);
  else {
    if (b <= d) {
      if (a <= c)
        printf("%d", b - c);
      else
        printf("%d", b - a);
    } else {
      if (a <= c)
        printf("%d", d - c);
      else
        printf("%d", d - a);
    }
  }
  return 0;
}