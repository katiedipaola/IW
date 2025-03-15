#include <stdio.h>
#include <stdlib.h>
int asc(const void *a, const void *b) {
  if (*(int *)a < *(int *)b)
    return -1;
  return 1;
}
int main() {
  int n;
  scanf("%d", &n);
  int i, j, k;
  int a[200005];
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  qsort(a, n, sizeof(int), asc);
  int c[1000006];
  for (i = 0; i < 1000006; i++)
    c[i] = 0;
  int ans = 0;
  for (i = 0; i < n; i++) {
    k = 0;
    for (j = 1; j * j <= a[i]; j++)
      if (a[i] % j == 0)
        if (c[j] + c[a[i] / j] > 0)
          k++;
    if (k == 0) {
      if (a[i] < a[i + 1])
        ans++;
    }
    c[a[i]]++;
  }
  printf("%d\n", ans);
  return 0;
}