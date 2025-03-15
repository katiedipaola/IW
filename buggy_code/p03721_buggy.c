#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long long a;
  long long b;
} data;

int sortfnc(const void *x, const void *y) {
  return ((data *)x)->a - ((data *)y)->b;
}

int main(void) {
  long long n, k, a, b, i;
  data p[131072];
  scanf("%lld%lld", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%lld%lld", &a, &b);
    p[i].a = a;
    p[i].b = b;
  }
  qsort(p, n, sizeof(data), sortfnc);
  for (i = 0; i < n; i++) {
    if (p[i].b >= k) {
      printf("%lld\n", p[i].a);
      return 0;
    }
    k -= p[i].b;
  }
  return 0;
}