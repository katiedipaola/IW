#include <stdio.h>
#include <stdlib.h>
long compare(const void *a, const void *b) { return *(long *)b - *(long *)a; }

int main() {
  long n = 0;
  long a[100000] = {};
  long long asum = 0;
  long b[100000] = {};
  long long bsum = 0;
  long diff[100000] = {};
  long long minussum = 0;
  long long plussum = 0;
  long minuscnt = 0;
  long result = 0;
  long i = 0;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    asum += a[i];
  }
  for (i = 0; i < n; i++) {
    scanf("%ld", &b[i]);
    bsum += b[i];
    diff[i] = a[i] - b[i];
    if (diff[i] < 0) {
      minussum += -diff[i];
      minuscnt++;
    }
  }

  if (bsum > asum) {
    printf("-1");
    return 0;
  }
  qsort(diff, n, sizeof(long), compare);

  for (i = 0; i < n; i++) {
    plussum += diff[i];
    if (plussum >= minussum) {
      break;
    }
  }
  if (minussum == 0) {
    result = 0;
  } else {
    result = i + 1 + minuscnt;
  }

  printf("%ld", result);
  /*for(i=0;i<n;i++){
    printf("%ld ",diff[i]);
  }*/
  // printf("#%lld",minussum);
  return 0;
}
