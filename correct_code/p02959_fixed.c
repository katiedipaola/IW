#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  int *A, *B;
  int i, tmp;
  long int sum;

  scanf("%d", &N);
  getchar();

  A = (int *)malloc(sizeof(int) * (N + 1));
  B = (int *)malloc(sizeof(int) * (N));

  for (i = 0; i < N + 1; i++)
    scanf("%d", &A[i]);
  getchar();
  for (i = 0; i < N; i++)
    scanf("%d", &B[i]);

  sum = 0;
  for (i = 0; i < N; i++) {
    if (B[i] > A[i]) {

      sum += A[i];
      tmp = B[i] - A[i];
      if (tmp > A[i + 1]) {
        sum += A[i + 1];
        A[i + 1] = 0;
      } else {
        sum += tmp;
        A[i + 1] -= tmp;
      }

    } else {
      sum += B[i];
    }
  }

  printf("%ld\n", sum);

  return 0;
}