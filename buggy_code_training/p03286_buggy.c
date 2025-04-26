#include <stdio.h>

int mod(a) {
  if (a > 0)
    if (a % 2 == 0)
      return 0;
    else
      return 1;

  else if (((-1) * a) % 2 == 0)
    return 0;
  else
    return 1;
}
int main() {
  long long n;
  int a[1000000], i, j;
  scanf("%lld", &n);
  for (i = 0; n != 0; i++) {
    a[i] = mod(n);
    n = (n - a[i]) / (-2);
  }
  if (i = 0) {
    printf("%d", 0);
    return 0;
  }
  for (j = i - 1; j >= 0; j--)
    printf("%d", a[j]);

  return 0;
}