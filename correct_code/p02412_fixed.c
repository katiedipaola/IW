#include <stdio.h>

int main() {
  int n, x;
  int a, b, c, d;
  while (1) {
    scanf("%d %d", &n, &x);
    if (!n && !x)
      break;
    d = 0;
    for (a = 1; a <= n; a++)
      for (b = a + 1; b <= n; b++)
        for (c = b + 1; c <= n; c++)
          if (a + b + c == x)
            d++;
    printf("%d\n", d);
  }
  return 0;
}