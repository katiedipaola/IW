#include <stdio.h>

int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d", n * (n - 1) + m * (m - 1));
  return 0;
}
