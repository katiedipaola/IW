#include <stdio.h>
long long a[200001], b[200001];
int main() {
  long long x, y, z;
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%lld", &a[i]);
  b[0] = 0;
  for (i = 1; i <= n; i++) {
    z = b[i - 1] + a[i - 1];
    b[i] = z % 1000000007;
  }
  // for(i=0;i<=n;i++) printf("%lld.",b[i]);
  x = 0;
  y = 0;
  for (i = 1; i <= n - 1; i++) {
    x = b[i] * a[i];
    x = x % 1000000007;
    y = y + x;
    y = y % 1000000007;
  }
  printf("%lld\n", y);
  return 0;
}