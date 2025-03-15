#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N, M, X;
  int *A;
  int i;
  int cost1 = 0, cost2 = 0;

  scanf("%d %d %d", &N, &M, &X);

  A = (int *)malloc(sizeof(int) * M);

  for (i = 0; i < M; i++)
    scanf("%d", &A[i]);

  if (X >= A[M]) {
    printf("0\n");
    return 0;
  }

  for (i = 0; A[i] < X && i < M; i++)
    cost1++;
  cost2 = M - cost1;

  if (cost1 < cost2)
    printf("%d\n", cost1);
  else
    printf("%d\n", cost2);

  return 0;
}
