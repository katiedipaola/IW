#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, k;
  int N;
  int NX = 0;
  int NY = 0;
  int max = 0;
  scanf("%d", &N);
  char S[N];
  char X[N];
  char Y[N];

  scanf("%s", S);
  NX = 0;
  NY = 0;

  for (j = 0; j < N; j++) {
    if (S[j] == 'W')
      NY++;
  }

  max = NY + NX;

  for (i = 1; i < N; i++) {
    if (S[i] == 'W')
      NY--;
    if (S[i - 1] == 'E')
      NX++;
    if (NY + NX > max)
      max = NY + NX;
  }

  printf("%d", N - max);

  return 0;
}