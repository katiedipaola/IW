#include <stdio.h>
int main() {
  int r, d, x, a, s, i;
  scanf("%d %d %d", &r, &d, &x);
  s = x;
  for (i = 0; i < 10; i++) {
    a = r * s - d;
    a = s;
    printf("%d\n", a);
  }
  return 0;
}
