#pragma warning(disable : 4996)
#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);

  int ans = 0;
  int i = 1;
  int w = n / i;
  int count = 0;
  while (w) {
    i *= 10;
    ++count;
    w = n / i;
  }

  switch (count) {
  case 6:
    ans = 90909;
    break;

  case 5:
    ans = 909;
    ans += (n - 9999);
    break;

  case 4:
    ans = 909;
    break;

  case 3:
    ans = 9;
    ans += (n - 99);
    break;

  case 2:
    ans = 9;
    break;

  case 1:
    ans = n;
    break;
  }
  //	printf("%d\n", count); test
  printf("%d\n", ans);
  return 0;
}