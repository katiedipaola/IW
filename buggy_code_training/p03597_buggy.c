#include <stdio.h>
int main() {
  int N, A, k;
  scanf("%d", N);
  scanf("%d", A);
  k = N * N - A;
  printf("%d\n", k);
  return 0;
}