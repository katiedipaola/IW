#include <stdio.h>

long long maxMy(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

long long DP[3001][3001][4];
long long Gift[3001][3001];
long long r, c, k;

int main() {
  scanf("%lld %lld %lld", &r, &c, &k);
  int i;
  for (i = 0; i <= r; i++) {
    for (int j = 0; j <= c; j++) {
      DP[i][j][0] = 0;
      DP[i][j][1] = 0;
      DP[i][j][2] = 0;
      DP[i][j][3] = 0;
      Gift[i][j] = 0;
    }
  }
  for (i = 0; i < k; i++) {
    long long rt, ct, vt;
    scanf("%lld %lld %lld", &rt, &ct, &vt);
    Gift[rt][ct] = vt;
  }
  for (i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      DP[i][j][0] = maxMy(maxMy(maxMy(DP[i - 1][j][0], DP[i - 1][j][1]),
                                maxMy(DP[i - 1][j][2], DP[i - 1][j][3])),
                          DP[i][j - 1][0]);
      DP[i][j][1] = DP[i][j - 1][1];
      DP[i][j][2] = DP[i][j - 1][2];
      DP[i][j][3] = DP[i][j - 1][3];
      DP[i][j][3] = maxMy(DP[i][j][3], DP[i][j][2] + Gift[i][j]);
      DP[i][j][2] = maxMy(DP[i][j][2], DP[i][j][1] + Gift[i][j]);
      DP[i][j][1] = maxMy(DP[i][j][1], DP[i][j][0] + Gift[i][j]);
    }
  }
  printf("%lld", maxMy(maxMy(DP[r][c][0], DP[r][c][1]),
                       maxMy(DP[r][c][2], DP[r][c][3])));
}