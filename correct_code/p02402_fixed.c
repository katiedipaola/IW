#include <stdio.h>
int main(void) {
  int i, n, x;
  int min = 0, max = 0;
  long sum = 0;
  scanf("%d", &n);
  scanf("%d", &x);
  min = max = sum = x;
  for (i = 1; i < n; i++) {
    scanf("%d", &x);
    if (min > x)
      min = x;
    if (max < x)
      max = x;
    sum += x;
  }
  printf("%d %d %ld\n", min, max, sum);
  return 0;
}
