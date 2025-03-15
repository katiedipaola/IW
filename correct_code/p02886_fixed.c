#include <stdio.h>

int main() {
  int n, a, b = 0;
  long m = 0;
  scanf("%d", &n);
  for (; n > 0; n--) {
    scanf("%d", &a);
    m += a * b;
    b += a;
  }
  printf("%ld", m);
  return (0);
}
