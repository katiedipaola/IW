#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a >= b ? a : b; }

void output(int x, int y, int **dp, char *s, char *t) {
  if (dp[x][y] == 0) {
    return;
  } else if (dp[x][y] == dp[x - 1][y]) {
    output(x - 1, y, dp, s, t);
  } else if (dp[x][y] == dp[x][y - 1]) {
    output(x, y - 1, dp, s, t);
  } else {
    output(x - 1, y - 1, dp, s, t);
    printf("%c", s[x]);
  }
}

int main() {
  int N, M, i, j;
  char *s = (char *)malloc(sizeof(char) * 3002);
  char *t = (char *)malloc(sizeof(char) * 3002);
  scanf("%s", &s[1]);
  scanf("%s", &t[1]);
  for (N = 0; s[N] != '\0'; N++)
    ;
  N--;
  for (M = 0; t[M] != '\0'; M++)
    ;
  M--;
  int **dp = (int **)malloc(sizeof(int *) * (N + 1));
  for (i = 0; i <= N; i++) {
    dp[i] = (int *)malloc(sizeof(int) * (M + 1));
    for (j = 0; j <= M; j++) {
      dp[i][j] = 0;
    }
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s[i] == t[j]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  output(N, M, dp, s, t);
  printf("\n");
  return 0;
}