#include <stdio.h>
#include <stdlib.h>

int main() {
  long long int n, m;
  scanf("%d%d", &n, &m);

  long long int a;
  a = n % m;
  if (a < m - a) {
    printf("%d", a);
  } else {
    printf("%d", m - a);
  }

  return 0;
}