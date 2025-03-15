#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
} /* 1,2,3,4.. */
int cmp_char(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
} /* a,b,c,d.. */
int cmp_str(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
} /* aaa,aab.. */
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
int a[100001], b[100001] = {0}, c[100001], idx[100001];

int des(const void *a, const void *b) { return c[*(int *)b] - c[*(int *)a]; }

int main(void) {
  int n, m;

  scanf("%d %d", &n, &m);

  int i, j;
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < m; i++)
    scanf("%d %d", &b[i], &c[i]);

  for (i = 0; i < m; i++)
    idx[i] = i;

  qsort(a, n, sizeof(int), acs);
  qsort(idx, m, sizeof(int), des);

  long long int max = 0;
  int now = 0;
  for (i = 0; i < n; i++) {
    if (b[idx[now]] > 0 && a[i] < c[idx[now]]) {
      a[i] = c[idx[now]];
      b[idx[now]]--;
      if (b[idx[now]] < 1)
        now++;
    } else
      break;
  }

  for (i = 0; i < n; i++)
    max += a[i];

  printf("%lld\n", max);
  return 0;
}
