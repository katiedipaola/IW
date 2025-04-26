#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  int a = n;
  int c, t, i;
  for (i = 0; i <= n; i++) {
    c = 0;
    t = i;
    while (t > 0) {
      c += t % 6;
      t /= 6;
    }
    t = n - i;
    while (t > 0) {
      c += t % 9;
      t /= 9;
    }
    if (a > c)
      a = c;
  }
  printf("%d/n", c);
  return 0;
}