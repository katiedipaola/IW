#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
  long n, a[200000], i, b, sorrow;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", a + i);
  }

  for (i = 0; i < n; i++) {
    a[i] -= i + 1;
  }

  qsort(a, n, sizeof(int), compare_int);

  b = a[n / 2];

  sorrow = 0;
  for (i = 0; i < n; i++) {
    sorrow += abs(a[i] - b);
  }

  printf("%d", sorrow);

  return 0;
}