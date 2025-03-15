#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r);
void quick_sort(int a[], int l, int r);

int main() {
  int n, k;
  int *h;
  int i;
  long long n_attack = 0;

  scanf("%d %d", &n, &k);

  if ((h = (int *)malloc(sizeof(int) * n)) == NULL) {
    printf("malloc");
    return 0;
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }

  quick_sort(h, 0, n - 1);

  for (i = 0; i < n; i++) {
    if (i < k) {
      continue;
    }
    n_attack += h[n - i - 1];
  }

  printf("%ld", n_attack);
  return 0;
}

int partition(int a[], int l, int r) {
  int i, j, pivot, t;

  i = l - 1;
  j = r;
  pivot = a[r];
  for (;;) {
    while (a[++i] < pivot) {
      ;
    }

    while (i < --j && pivot < a[j]) {
      ;
    }

    if (i >= j) {
      break;
    }

    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }

  t = a[i];
  a[i] = a[r];
  a[r] = t;

  return i;
}

void quick_sort(int a[], int l, int r) {
  int v;

  if (l >= r) {
    return;
  }

  v = partition(a, l, r);
  quick_sort(a, l, v - 1);
  quick_sort(a, v + 1, r);
}
