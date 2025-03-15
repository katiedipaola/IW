#include <stdio.h>
int main(void) {
  long long int a[200001], n, i, j, sum = 0;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
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
  printf("%lld\n", sum);
  return 0;
}