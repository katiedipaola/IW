#include <stdio.h>

int main() {
  int n;
  if (scanf("%d", &n) == 1) {
  }
  int a[n];
  int i;
  int b[n];
  for (i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) == 1) {
    }
    b[a[i] - 1] = i + 1;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  return 0;
}