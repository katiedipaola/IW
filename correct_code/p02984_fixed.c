#include <stdio.h>
int main() {
  long long n, i, a = 0, b = 0, m, d[100010];
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &d[i]);
    if (i % 2 == 0)
      a += d[i];
    b += d[i];
  }
  m = a + a - b;
  printf("%lld", m);
  for (i = 0; i < n - 1; i++) {
    m = d[i] * 2 - m;
    printf(" %lld", m);
  }
  printf("\n");
  return 0;
}
