#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b) {
  int aNum = *(int *)a;
  int bNum = *(int *)b;

  return aNum - bNum;
}

int main(void) {
  int n, m, x[10 * 10 * 10 * 10 * 10], i, ans = 0, diff[10 * 10 * 10 * 10 * 10];

  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &x[i]);
  }
  if (n >= m) {
    ans = 0;
    printf("%d\n", ans);
    return 0;
  }

  qsort(x, m, sizeof(int), compare);
  for (i = 0; i < m - 1; i++) {
    diff[i] = x[i + 1] - x[i];
  }

  qsort(diff, m - 1, sizeof(int), compare);
  for (i = 0; i < n + 1; i++) {
    ans = ans + diff[i];
  }
  if (n == 1) {
    ans = x[m - 1] - x[0];
    printf("%d\n", ans);
    return 0;
  }

  printf("%d\n", ans);

  return 0;
}
