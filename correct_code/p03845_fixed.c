#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int n, a[100001] = {0};
  int i, j;
  int m, q, w;
  long long int ans = 1;
  int flag = 0;
  int sum;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &q, &w);
    sum = 0;
    for (j = 0; j < n; j++) {
      sum += a[j];
    }
    sum -= a[q - 1];
    sum += w;
    printf("%d\n", sum);
  }
  return 0;
}