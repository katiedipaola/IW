#include <stdio.h>
#define MAXN 1 << 17
int a[MAXN], n;
int solve(void) {
  int res = 1;
  int mov = 0;
  for (int i = 0; i < n - 2; i++) {
    if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
      continue;
    else if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2] && mov != 2)
      mov = 1;
    else if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2] && mov != 1)
      mov = 2;
    else {
      mov = 0;
      res++;
      i++;
    }
  }
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("%d", solve());
  return 0;
}