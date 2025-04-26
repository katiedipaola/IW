#include <stdio.h>

#define N 10001

int main() {
  int n, i, fl[N] = {0};
  int a[N], b[N], c = 0, t;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (fl[a[i]] == 1)
      b[c++] = a[i];
    else
      fl[a[i]] = 1;
  }
  t = c;
  while (c >= 3)
    c = c / 3 + c % 3;
  printf("%d\n", n - t - c % 2);
  return 0;
}