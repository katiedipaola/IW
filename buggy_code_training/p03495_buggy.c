#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main() {
  int n, k, ans = 0;
  int t, a[200010] = {};
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    a[t]++;
  }
  qsort(a, n, sizeof(int), comp);
  for (int i = k; i < n; i++) {
    ans += a[i];
  }
  printf("%d", ans);
  return 0;
}