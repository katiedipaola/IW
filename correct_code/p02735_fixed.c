#include <stdio.h>
#define INF 1001001001
int min(int x, int y) { return x < y ? x : y; }
int main() {
  int h, w, dp[100][100];
  char s[101][101];
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dp[i][j] = INF;
    }
  }
  if (s[0][0] == '#')
    dp[0][0] = 1;
  else
    dp[0][0] = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i != 0)
        dp[i][j] =
            min(dp[i][j],
                dp[i - 1][j] + (s[i][j] == '#' && s[i - 1][j] == '.' ? 1 : 0));
      if (j != 0)
        dp[i][j] =
            min(dp[i][j],
                dp[i][j - 1] + (s[i][j] == '#' && s[i][j - 1] == '.' ? 1 : 0));
    }
  }
  printf("%d\n", dp[h - 1][w - 1]);
  return 0;
}