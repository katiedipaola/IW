#include <stdio.h>

int main() {
  long long n = 0;
  long long m = 0;
  long long result = 0;
  scanf("%lld %lld", &n, &m);
  if (n == 1) {
    if (m == 1) {
      result = 1;
    } else if (m == 2) {
      result = 0;
    } else {
      result = m - 2;
    }
  } else if (n == 2) {
    result = 0;
  } else {
    if (m == 1) {
      result = n - 2;
    } else if (m == 2) {
      result = 0;
    } else {
      result = (n - 2) * (m - 2);
    }
  }
  printf("%lld", result);
  return 0;
}
