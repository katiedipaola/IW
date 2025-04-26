#include <stdio.h>
int main(void) {
  int a[200001], n, i, j, sum = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      sum += a[i] - a[i + 1];
      a[i + 1] = a[i];
    }
  }
  printf("%d\n", sum);
  return 0;
}