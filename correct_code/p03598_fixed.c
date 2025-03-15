#include <stdio.h>

int main() {
  int n, k, ans = 0;
  scanf("%d%d", &n, &k);

  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    ans += (x < k - x) ? x : k - x;
  }

  printf("%d", ans * 2);
  return 0;
}