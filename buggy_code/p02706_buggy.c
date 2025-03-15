#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int n, m, a[10000];
  int i;
  long long int sum = 0;

  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (sum < n) {
    printf("%lld", sum - n);
  } else {
    printf("-1");
  }
  return 0;
}
