#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, *a, i, j, dif;
  unsigned long sum, min = ULONG_MAX;
  scanf("%d", &N);
  a = (int *)malloc(N * sizeof(int));
  for (i = 0; i < N; i++) {
    scanf("%d", a + i);
  }
  for (i = (-100); i <= 100; i++) {
    sum = 0;
    for (j = 0; j < N; j++) {
      dif = a[j] - i;
      sum += (unsigned long)(dif * dif);
    }
    if (min > sum)
      min = sum;
  }
  printf("%lu\n", min);
  free(a);
  return 0;
}