#include <stdio.h>

int main() {
  int a, b, c;
  int a2, b2, c2;
  int ans = 0;
  scanf(" %d %d %d", &a, &b, &c);

  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    if (a == b && b == c) {
      puts("-1");
      return 0;
    }
    a2 = a / 2;
    b2 = b / 2;
    c2 = c / 2;
    a = b2 + c2;
    b = a2 + c2;
    c = a2 + b2;
    ans++;
  }

  printf("%d\n", ans);

  return 0;
}