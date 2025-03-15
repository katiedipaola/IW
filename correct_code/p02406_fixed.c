#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
int main() {
  int n, i, x;
  int f;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    for (x = i, f = 0; 0 < x; x /= 10)
      if (!(i % 3) || (x % 10 == 3))
        f = 1;
    if (f)
      printf(" %d", i);
  }
  putchar('\n');
  return 0;
}