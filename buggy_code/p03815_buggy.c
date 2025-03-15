#include <stdio.h>
#define rep(i, n) for (i = 0; i < n; i++)

int main() {
  int x;
  scanf("%d", &x);

  int ans = x / 11 * 2;
  if (x % 11 > 6)
    ans += 2;
  else if (x % 11 > 0)
    ans++;

  printf("%d\n", ans);
  return 0;
}