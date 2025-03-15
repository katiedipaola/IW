#include <stdio.h>
int main() {
  int n, A, B, C, count = 0;
  int i, j, k, temp;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // sorting

  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  for (i = 0; i < n; i++) {
    A = a[i];
    for (j = i; j < n; j++) {
      B = a[j];
      for (k = j; k < n; k++) {
        C = a[k];
        if (C <= A + B) {
          break;
        }
        count++;
      }
    }
  }
  printf("%d", count);
}
