#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define d_flag 0
int v[50], n;
int get[100];
int c(const void *a, const void *b) { return ((*((int *)a)) - (*((int *)b))); }
int d_count = 100000;
void get_value(int a, int b) {
  int itr = 0;
  if (a + b > n) {
    for (itr = 0; itr < n; itr++) {
      get[itr] = v[itr];
    }
    qsort(get, n, sizeof(int), c);
    return;
  }
  while (itr < a) {
    get[itr] = v[itr];
    itr++;
  }
  itr = 0;
  while (itr < b) {
    get[itr + a] = v[n - itr - 1];
    itr++;
  }
  qsort(get, a + b, sizeof(int), c);
}

int main() {
  int i, k, j, sum;

  scanf("%d%d", &n, &k);

  for (i = 0; i < n; i++) {
    d_count -= d_flag;
    if (d_count < 0) {
      printf("AAA\n");
      break;
    }

    scanf("%d", &v[i]);
  }
  if (k >= n * 2) {
    if (d_flag)
      printf("take all.\n");
    sum = 0;
    for (i = 0; i < n; i++)
      sum += (v[i] > 0 ? v[i] : 0);
    printf("%d", sum);
    return 0;
  }

  int waste = 0, max = 0;
  for (; waste * 2 <= k; waste++) {
    // a+b=k-waste
    for (i = 0; i <= k - waste; i++) {
      get_value(i, k - waste - i);
      if (d_flag) {
        printf("waste:%d:", waste);
        for (j = 0; j < k - waste; j++)
          printf(" %d", get[j]);
      }

      j = 0;
      sum = 0;
      while (j < waste) {
        sum += get[j] > 0 ? get[j] : 0;
        j++;
      }
      while (j < k - waste) {
        sum += get[j++];
      }
      if (d_flag)
        printf(" >>> %d\n", sum);

      if (max < sum)
        max = sum;
    }
  }

  if (d_count < 0)
    printf("err.\n");
  printf("%d\n", max);

  return 0;
}
