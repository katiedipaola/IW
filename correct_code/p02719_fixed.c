#include <stdio.h>
#include <stdlib.h>

int main() {
  long int n, m;
  scanf("%ld%ld", &n, &m);

  long int a;
  a = n % m;

  if (a < m - a) {
    printf("%ld", a);
  } else {
    printf("%ld", m - a);
  }

  return 0;
}