#include <stdio.h>

int main() {
  int a, b, c, d, e;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  a = a > b ? b : a > c ? c : a;
  d = d > e ? e : d;
  printf("%d\n", -50 + a + d);
  return 0;
}