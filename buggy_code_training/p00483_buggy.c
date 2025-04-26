#include <stdio.h>
#include <string.h>

char field[1001][1002];
int J[1001][1001], O[1001][1001], I[1001][1001];

int main(void) {
  int M, N, K, i, j, a, b, c, d;

  scanf("%d%d", &M, &N);
  scanf("%d", &K);
  for (i = 0; i <= M; i++) {
    for (j = 0; j <= N; j++) {
      J[i][j] = O[i][j] = I[i][j] = 0;
    }
  }
  for (i = 1; i <= M; i++) {
    scanf("%s\n", &(field[i][1]));
    for (j = 1; j <= N; j++) {
      J[i][j] = J[i][j - 1] + J[i - 1][j] - J[i - 1][j - 1];
      O[i][j] = O[i][j - 1] + O[i - 1][j] - O[i - 1][j - 1];
      I[i][j] = I[i][j - 1] + I[i - 1][j] - I[i - 1][j - 1];
      switch (field[i][j]) {
      case 'J':
        J[i][j]++;
        break;
      case 'O':
        O[i][j]++;
        break;
      case 'I':
        I[i][j]++;
        break;
      default:
        break;
      }
    }
  }
  for (i = 0; i < M; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d %d %d\n", J[c][d] - J[c][b - 1] - J[a - 1][d] + J[a - 1][b - 1],
           O[c][d] - O[c][b - 1] - O[a - 1][d] + O[a - 1][b - 1],
           I[c][d] - I[c][b - 1] - I[a - 1][d] + I[a - 1][b - 1]);
  }
  return 0;
}