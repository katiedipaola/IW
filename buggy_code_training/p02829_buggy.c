#include "math.h"
#include "stdio.h"

int main() {
  int a, b, ans;
  scanf("%d,%d", &a, &b);
  if (a == 1 && b == 2)
    ans = 3;
  if (a == 1 && b == 3)
    ans = 2;
  if (a == 2 && b == 1)
    ans = 3;
  if (a == 2 && b == 3)
    ans = 1;
  if (a == 3 && b == 2)
    ans = 1;
  if (a == 3 && b == 1)
    ans = 2;
  printf("%d", ans);
  return 0;
}