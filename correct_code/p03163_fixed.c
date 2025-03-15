#include <stdio.h>

int N, W;

int w[101];
int v[101];

long dp[101][100001];

void selec(int);

int main(void) {
  int i, j;

  scanf("%d%d", &N, &W);

  for (i = 1; i < N + 1; i++) {
    scanf("%d%d", &w[i], &v[i]);
  }

  for (j = 0; j < W + 1; j++) {
    dp[0][j] = 0;
  }

  for (i = 1; i < N + 1; i++) {
    selec(i);
  }

  long max = 0;

  for (i = 1; i < W + 1; i++) {
    if (max < dp[N][i]) {
      max = dp[N][i];
    }
  }

  printf("%ld", max);

  return 0;
}

void selec(int i) {
  int j;

  for (j = 1; j < W + 1; j++) {
    if (j - w[i] >= 0 && dp[i - 1][j] < dp[i - 1][j - w[i]] + v[i]) {
      dp[i][j] = dp[i - 1][j - w[i]] + v[i];
    } else {
      dp[i][j] = dp[i - 1][j];
    }
  }
  return;
}