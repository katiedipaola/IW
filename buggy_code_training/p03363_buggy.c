#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F(i, a, n) for (int i = a; i < n; i++)

int compare(const void *n1, const void *n2) {
  if (*(long *)n1 > *(long *)n2)
    return 1;
  else if (*(long *)n1 < *(long *)n2)
    return -1;
  else
    return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  long sum[n + 1];
  sum[0] = 0;
  long tmp;
  F(i, 0, n) {
    scanf("%d", &tmp);
    sum[i + 1] = sum[i] + tmp;
  }
  qsort(sum, n, sizeof(long), compare);

  long count = 0, s = 0;
  F(j, 0, n) {
    if (sum[j] == sum[j + 1]) {
      count++;
      continue;
    }
    s += count * (count - 1) / 2;
    count = 1;
  }
  s += count * (count - 1) / 2;

  printf("%ld", s);
  return 0;
}