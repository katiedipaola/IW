#include <stdio.h>

int main(void) {
  int ans;
  int n, t, e;
  int i;
  int x;

  ans = -1;
  scanf("%d %d %d", &n, &t, &e);

  for (i = 0; i < n; i++) {
    scanf("%d", &x);

    if (t % x <= e || t % x >= x - e) {
      ans = i + 1;
    }
  }

  printf("%d\n", ans);

  return (0);
}