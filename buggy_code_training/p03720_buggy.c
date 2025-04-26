#include <stdio.h>
int N, M, a, b, A[50], i;
int main() {
  scanf("%d%d", &N, &M);
  for (i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    A[a]++;
    A[b]++;
  }
  for (i = 0; i < N; i++) {
    printf("%d\n", A[i]);
  }
}
