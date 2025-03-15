#include <stdio.h>
int main() {
  int n, a, b = 0, s = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    b += a;
    s += a / 2;
    b = a ? b % 2 : 0;
  }
  printf("%d\n", s);
  return 0;
}
