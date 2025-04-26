#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
  int mass;
} bigint;

int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int compare_bigint(const void *p, const void *q) {
  return ((bigint *)q)->mass - ((bigint *)p)->mass;
}

int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

void calic(int *A, int n, bigint *ma, int *a) {
  int i;
  int k = 1;
  int j = 0;
  for (i = 0; i < n; i++) {
    ma[i].mass = 0;
    ma[i].num = 0;
  }
  for (i = 1; i < n / 2; i++) {
    if (A[i] == A[i - 1]) {
      k++;
    } else {
      ma[j].mass = k;
      ma[j].num = A[i - 1];
      j++;
    }
  }
  ma[j].mass = k;
  ma[j].num = A[n / 2 - 1];
  a[0] = j + 1;
}

int main() {
  int n, i, ans;
  scanf("%d", &n);
  int A[n / 2];
  int B[n / 2];
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      scanf("%d", &A[i / 2]);
    } else {
      scanf("%d", &B[(i - 1) / 2]);
    }
  }

  bigint ma[n];
  bigint mb[n];
  int a[1];
  int b[1];
  qsort(A, n / 2, sizeof(int), compare_int);
  qsort(B, n / 2, sizeof(int), compare_int);
  calic(A, n, ma, a);
  calic(B, n, mb, b);
  qsort(ma, a[0], sizeof(bigint), compare_bigint);
  qsort(mb, b[0], sizeof(bigint), compare_bigint);

  if (ma[0].num == mb[0].num) {
    ans = min(n - ma[1].mass - mb[0].mass, n - ma[0].mass - mb[1].mass);
  } else {
    ans = n - (ma[0].mass + mb[0].mass);
  }
  printf("%d", ans);
  return 0;
}
