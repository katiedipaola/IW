#include <stdio.h>
#include <stdlib.h>

int comp(const void *c1, const void *c2);

int main() {
  long int n, a[1001], max1 = 0, max2 = 0, i;

  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  qsort(a, n, sizeof(long int), comp);

  for (i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      max1 = a[i];
      break;
    }
  }
  for (i++; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      max2 = a[i];
      break;
    }
  }

  printf("%ld\n", max1 * max2);

  return 0;
}

int comp(const void *c1, const void *c2) {
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;

  if (tmp1 > tmp2)
    return -1;
  if (tmp1 == tmp2)
    return 0;
  if (tmp1 < tmp2)
    return 1;
}