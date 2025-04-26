#include <stdio.h>
#include <stdlib.h>
int sl(const void *a, const void *b) {
  if (*(int *)a > *(int *)b)
    return 1;
  return -1;
}
int ls(const void *a, const void *b) {
  if (*(int *)a < *(int *)b)
    return 1;
  return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  int a[n], b[n], c[n];
  long long ans = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &b[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &c[i]);
  qsort(a, n, sizeof(int), sl);
  qsort(b, n, sizeof(int), sl);
  qsort(c, n, sizeof(int), ls);

  long long ac = 0, cc = 0, j = 0, k = 0;
  while (c[k] > b[0] && k < n) {
    k++;
    cc++;
  }
  k--;
  for (int i = 0; i < n; i++) {
    for (; a[j] < b[i] && j < n; j++)
      ac++;
    for (; c[k] <= b[i]; k--)
      cc--;
    // printf("i=%d,ac=%d,cc=%d\n",i,ac,cc);
    ans += ac * cc;
  }
  printf("%lld", ans);

  return 0;
}
