#include <stdio.h>
int main(void) {
  int N;
  int B[99];
  int A[100];
  int i;
  int sum;

  scanf("%d", &N);
  if (N <= 100) {
    for (i = 0; i < N - 1; i++) {
      scanf("%d", &B[i]);
    }
  }

  sum = B[0];
  for (i = 0; i < N - 1; i++) {
    if (B[i] <= B[i + 1]) {
      sum = sum + B[i];
    } else {
      sum = sum + B[i + 1];
    }
  }
  sum = sum + B[N - 2];
  printf("%d", sum);
  return (0);
}
