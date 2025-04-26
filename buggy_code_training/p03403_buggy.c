#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, i, sum = 0, ans;
  scanf("%d", &n);
  int a[n + 2];
  a[0] = a[n + 1] = 0;
  for (i = 1; i < n + 1; i++)
    scanf("%d", &a[i]);
  for (i = 0; i < n + 1; i++)
    sum += abs(a[i] - a[i + 1]);
  for (i = 1; i + 1; i++) {
    ans = sum + abs(a[i - 1] - a[i + 1]) -
          (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]));
    printf("%d\n", ans);
  }
  return 0;
}