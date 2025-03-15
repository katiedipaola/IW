/*
  AOJ #0347
  title:
  @kankichi573
 */
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
double max(double x, double y) {
  if (x > y)
    return (x);
  else
    return (y);
}
int n, ar[1000];

int comp(const void *a, const void *b) {

  if (*(int *)a < *(int *)b) {
    return -1;
  } else if (*(int *)a == *(int *)b) {
    return 0;
  }
  return 1;
}

int main() {
  int i, m2;
  double ret;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &ar[i]);
  qsort(ar, n, sizeof(int), comp);
  ret = 0.0;
  m2 = ar[n - 2] + ar[n - 1];

  for (i = 0; i < n - 2; i++)
    ret = max(ret, (double)m2 / (ar[i + 1] - ar[i]));
  ret = max(ret, (ar[n - 1] + ar[n - 4]) / (ar[n - 2] - ar[n - 3]));
  ret = max(ret, (ar[n - 3] + ar[n - 4]) / (ar[n - 2] - ar[n - 1]));
  printf("%lf\n", ret);
  return (0);
}