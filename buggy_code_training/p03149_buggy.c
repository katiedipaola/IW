#include <stdio.h>

int main(void) {
  int a, b, c, d;
  int p = 0;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  p = a * 1000 + b * 100 + c * 10 + d;
  if (p == 1479 || p == 1497 || p == 1749 || p == 1794 || p == 1947 ||
      p == 1974) {
    printf("YES");
  } else if (p == 4179 || p == 4197 || p == 4719 || p == 4791 || p == 4917 ||
             p == 4971) {
    printf("YES");
  } else if (p == 7149 || p == 7194 || p == 7419 || p == 7491 || p == 7914 ||
             p == 7941) {
    printf("YES");
  } else if (p == 9147 || p == 9174 || p == 9417 || p == 9471 || p == 9714 ||
             p == 9741) {
    printf("YES");
  }
  printf("NO");

  return 0;
}