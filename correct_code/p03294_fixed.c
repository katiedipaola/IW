#include <stdio.h>

int main() {
  int i, N, ans = 0, a;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &a);
    ans += a - 1;
  }
  printf("%d\n", ans);
  return 0;
}
