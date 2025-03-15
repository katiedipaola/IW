#include <stdio.h>
int main() {
  int i, K, X, A, count = 0;
  scanf("%d %d", &K, &X);
  A = X - (K - 1);
  for (i = 0; i <= 2 * K - 2; i++) {
    count = A + i;
    printf("%d\t", count);
    count = A;
  }
  return 0;
}