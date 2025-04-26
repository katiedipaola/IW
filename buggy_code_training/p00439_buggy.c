#include <stdio.h>
#include <string.h>
int main(void) {
  int n, k, i, a[100000], max, sum;
  scanf("%d %d", &n, &k);
  while (1) {
    max = sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (i >= k) {
        sum = sum - a[i - 4] + a[i];
        if (sum > max) {
          max = sum;
        }
      } else if (i < k) {
        max += a[i];
        sum += a[i];
      }
    }
    printf("%d\n", max);
    scanf("%d %d", &n, &k);
    if (n == 0 && k == 0)
      break;
  }
  return 0;
}