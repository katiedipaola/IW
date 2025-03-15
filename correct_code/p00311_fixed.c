#include <stdio.h>
int main(void) {
  int h1, h2, k1, k2, a, b, c, d, g, m;
  scanf("%d%d%d%d%d%d%d%d", &h1, &h2, &k1, &k2, &a, &b, &c, &d);
  g = h1 * a + h2 * b + h1 / 10 * c + h2 / 20 * d;
  m = k1 * a + k2 * b + k1 / 10 * c + k2 / 20 * d;
  if (g < m) {
    printf("kenjiro\n");
  } else if (m < g) {
    printf("hiroshi\n");
  } else {
    printf("even\n");
  }
  return 0;
}