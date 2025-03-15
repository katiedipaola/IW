#include <stdio.h>

void swap(int x[], int i, int j) {
  int tmp;
  tmp = x[i];
  x[i] = x[j];
  x[j] = tmp;
}

void qsort(int a[], int b[], int c[], int left, int right) {
  int i, j;
  int pivot;
  i = left;
  j = right;
  pivot = c[(left + right) / 2];
  while (1) {
    while (c[i] < pivot)
      i++;
    while (pivot < c[j])
      j--;
    if (i >= j)
      break;
    swap(c, i, j);
    swap(a, i, j);
    swap(b, i, j);
    i++;
    j--;
  }

  if (left < i - 1)
    qsort(a, b, c, left, i - 1);
  if (j + 1 < right)
    qsort(a, b, c, j + 1, right);
}

int main() {
  int N;
  scanf("%d", &N);
  int a[N];
  int b[N];
  int c[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &a[i], &b[i]);
    c[i] = a[i] + b[i];
  }
  long takahashi = 0;
  long aoki = 0;
  qsort(a, b, c, 0, N - 1);
  for (int i = N - 1; i >= 0; i--) {
    if (i % 2 == (N - 1) % 2)
      takahashi += a[i];
    else
      aoki += b[i];
  }
  printf("%ld\n", takahashi - aoki);
  return 0;
}
