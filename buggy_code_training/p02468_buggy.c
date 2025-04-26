#include <stdio.h>
int main(void) {
  long long m, n;
  scanf("%lld%lld", &m, &n);
  long long r = 1000000007;
  int b[32];
  long long na = n;
  int i = 0;
  while (na != 0) {
    b[i] = na % 2;
    na /= 2;
    i++;
  }
  long long a[32];
  a[0] = m;
  for (int j = 1; j <= i; j++) {
    a[j] = a[j - 1] * a[j - 1];
    a[j] = a[j] % r;
  }
  long long ans = 1;
  for (int j = 0; j <= i; j++) {
    if (b[j] != 0) {
      ans *= a[j];
      ans = ans % r;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
