#include <limits.h>
#include <stdio.h>
long long abs(long long n) {
  if (n >= 0)
    return n;
  else
    return -n;
}
int main() {
  int A[200010], n, i, t;
  long long sum, x, min, a;
  sum = 0;
  x = 0;
  min = LLONG_MAX;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  for (i = 1; i <= n - 1; i++) {
    x += A[i];
    a = abs(sum - 2 * x);
    if (a < min)
      min = a;
  }
  printf("%l64d\n", min);
  return 0;
}