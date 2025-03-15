#include <stdio.h>
int bubble_sort(int *a, int n, int change);

int main(void) {
  int n;
  int change;
  int i;
  int a[100] = {};

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    change = 0;
    change = bubble_sort(a, n, change);
    printf("%d\n", change);
  }
  return 0;
}

int bubble_sort(int *a, int n, int change) {
  int i, j, tmp;
  int n2;

  n2 = n;
  for (j = 1; j < n; j++) {
    for (i = 0; i < n2 - 1; i++) {
      if (a[i] > a[i + 1]) {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        change++;
      }
    }
    n2--;
  }
  return change;
}