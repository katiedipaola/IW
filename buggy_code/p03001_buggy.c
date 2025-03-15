#include <stdio.h>

int main() {
  long long int w, h, ans, x, y;
  scanf("%lld %lld %lld %lld", &w, &h, &x, &y);
  printf("%f ", w * h / 2.0);
  if (w % 2 == 0 && w / 2 == x || h % 2 == 0 && h / 2 == y)
    printf("1");
  else
    printf("0");
}
