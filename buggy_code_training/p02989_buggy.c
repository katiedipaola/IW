#include <stdio.h>
#include <stdlib.h>

// -- 比較用の関数 cmp --
int cmp(const void *p, const void *q) { return *(int *)p - *(int *)q; }
// ---------------------------------------

int main(void) {
  int n;
  int x, i;
  int a[100000];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  qsort(a, n, sizeof(int), cmp);
  x = a[n / 2] - a[n / 2 - 1];
  printf("%d¥n", x);
}
