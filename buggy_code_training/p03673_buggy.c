#include <stdio.h>

int main(void) {
  int n, i, j;
  scanf("%d", &n);
  int a[n];
  int b[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  if (n % 2 == 0) {
    for (j = 0; j < n / 2; j++) {
      b[j] = a[n - 1 - (j * 2)];
    }
    for (j = 0; j < n / 2; j++) {
      b[j + n / 2] = a[2 * j];
    }
  } else {
    for (j = 0; j < n + 1 / 2; j++) {
      b[j] = a[n - 1 - (j * 2)];
    }
    for (j = 0; j < n / 2; j++) {
      b[j + n + 1 / 2] = a[2 * j + 1];
    }
  }

  for (i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}