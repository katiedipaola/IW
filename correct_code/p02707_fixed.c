#include <stdio.h>
int main() {

  int N, A, i, B[200001] = {0};
  scanf("%d", &N);
  for (i = 1; i < N; i++) {
    scanf("%d", &A);
    B[A]++;
  }
  for (i = 1; i <= N; i++)
    printf("%d\n", B[i]);
  return 0;
}
