#include <stdio.h>
#include <stdlib.h>

int duzina[101][10001], prethodni[1001][1001];

int main() {
  int N, M, W[101], P[101], optimalni[1000];
  int i, j;

  scanf("%d", &N);
  scanf("%d", &M);

  for (i = 0; i < N; ++i) {
    scanf("%d", &P[i]);
    scanf("%d", &W[i]);
  }

  for (i = 0; i <= M; ++i) {
    duzina[0][i] = 0;
    prethodni[0][i] = 0;
  }

  for (i = 1; i <= N; ++i) {
    for (j = 0; j <= M; ++j) {

      if (W[i - 1] > j) {
        duzina[i][j] = duzina[i - 1][j];
        continue;
      }

      int k;

      k = ((j - W[i - 1]) > 0) ? duzina[i - 1][j - W[i - 1]] : 0;

      if (duzina[i - 1][j] > (k + P[i - 1])) {
        duzina[i][j] = duzina[i - 1][j];
        prethodni[i][j] = 0;
      } else {
        duzina[i][j] = k + P[i - 1];
        prethodni[i][j] = 1;
      }
    }
  }

  printf("%d\n", duzina[N][M]);

  return 0;
}