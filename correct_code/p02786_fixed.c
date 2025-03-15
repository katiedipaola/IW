#include <stdio.h>

int main() {
  long n = 0, m = 1;
  scanf("%ld", &n);
  while (n != 0) {
    n = n >> 1;
    m = m << 1;
  }
  printf("%ld", m - 1);
  return 0;
}
