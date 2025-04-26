#include <stdio.h>
int main(void) {
  int n, x, y, b, p, i, r;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x, &y, &b, &p);
    r = x * b + y * p;
    if (b >= 5 && p >= 2) {
      r = r * 0.8;
    } else if (b >= 5 && p < 2 && r > (x * b + y * 2) * 0.8) {
      r = (x * b + y * 2) * 0.8;
    } else if (b < 5 && p >= 2 && r > (x * 5 + y * p) * 0.8) {
      r = (x * 5 + y * p) * 0.8;
    } else if (b < 5 && b < 2 && r > (x * 5 + y * 2) * 0.8) {
      r = (x * 5 + y * 2) * 0.8;
    }
    printf("%d\n", r);
  }
  return 0;
}