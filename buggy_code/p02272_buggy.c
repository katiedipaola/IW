#include <stdio.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count = 0;

int main() {

  int n, i;
  int s[10000000];

  scanf("%d", &n);

  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);

  mergeSort(s, 0, n);

  for (i = 0; i < n; i++) {
    if (i == n - 1)
      printf("%d\n", s[i]);
    else
      printf("%d ", s[i]);
  }

  printf("%d\n", count);

  return 0;
}

void mergeSort(int *s, int left, int right) {

  int mid;

  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(s, left, mid);
    mergeSort(s, mid, right);

    merge(s, left, mid, right);
  }
}

void merge(int *s, int left, int mid, int right) {

  int n1, n2, i, k, j;

  n1 = mid - left;
  n2 = right - mid;

  int l[n1 + 1], r[n2 + 1];

  for (i = 0; i <= n1 - 1; i++)
    l[i] = s[left + i];

  for (i = 0; i <= n2 - 1; i++)
    r[i] = s[mid + i];

  l[n1] = 1000000;
  r[n2] = 1000000;

  i = 0;
  j = 0;

  for (k = left; k <= right - 1; k++) {

    count++;

    if (l[i] <= r[j]) {
      s[k] = l[i];
      i = i + 1;
    } else {
      s[k] = r[j];
      j = j + 1;
    }
  }
}
