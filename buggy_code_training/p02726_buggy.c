#include <math.h>
#include <stdio.h>

int min(int a, int b) {
  if (a >= b)
    return b;
  else
    return a;
}

int main() {
  int n, x, y, ans[2000] = {};
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      ans[min(j - i, abs(x - i) + abs(y - j) + 1) - 1]++;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}