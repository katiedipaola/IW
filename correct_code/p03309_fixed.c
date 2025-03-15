#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
  long n, a[200000], i, b, sorrow;

  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", a + i);
  }

  for (i = 0; i < n; i++) {
    a[i] -= i + 1;
  }

  qsort(a, n, sizeof(long), compare_int);

  b = a[n / 2];

  sorrow = 0;
  for (i = 0; i < n; i++) {
    sorrow += abs(a[i] - b);
  }

  printf("%ld", sorrow);

  return 0;
}