/*????\¨(Vote)*/
#include <stdio.h>
int main() {
  int i, j, x, y, z, N, M;
  int A[1000] = {0};
  int B[1000] = {0};
  int data[1000] = {0};
  scanf("%d %d", &N, &M);
  for (i = 1; i - 1 < N; i++) {
    scanf("%d", &A[i - 1]);
  }
  for (j = 1; j - 1 < M; j++) {
    scanf("%d", &B[j - 1]);
  }
  for (j = 1; j - 1 < M; j++) {
    x = 0;
    for (i = N; 1 < i; i--) {
      if (A[i - 1] <= B[j - 1]) {
        x = i - 1;
      }
    }
    data[x]++;
  }
  y = data[0];
  for (i = 1; i - 1 < N; i++) {
    if (y < data[i - 1]) {
      y = data[i - 1];
      z = i;
    }
  }
  printf("%d\n", z);
  return 0;
}