#include <stdio.h>
#define MAX 100000

int partition(int[], int, int);
int main() {
  int A[MAX], n, i, same;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  same = partition(A, 0, n - 1);
  for (i = 0; i < n; i++) {
    if (i == same) {
      printf("[%d] ", A[same]);
      continue;
    }
    if (i == n - 1)
      printf("%d\n", A[i]);
    else
      printf("%d ", A[i]);
  }
  return 0;
}

int partition(int A[], int p, int r) {
  int x, i, j, a;

  x = A[r];
  i = p - 1;

  for (j = p; j < r; j++) {
    if (A[j] <= x) {
      i = i + 1;
      a = A[j];
      A[j] = A[i];
      A[i] = a;
    }
  }
  a = A[i + 1];
  A[i + 1] = A[r];
  A[r] = a;

  return i + 1;
}
