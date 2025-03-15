#include <stdio.h>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int X = (A); X <= (Y); ++X)
#define _rep2(X, Y) for (int X = 0; X < (Y); ++X)
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
typedef long long ll;

#define MAX_N 50
#define MAX_A 50
int N, A;
int x[MAX_N + 1];
ll dp[MAX_N + 1][MAX_N + 1][MAX_N * MAX_A + 1];

int main() {
  scanf("%d %d", &N, &A);
  rep(i, 1, N) scanf("%d", &x[i]);

  rep(i, N) dp[i][0][0] = 1;

  rep(i, 1, N) {
    rep(j, 1, i) {
      rep(k, 1, N * A) {
        if (k < x[i]) {
          dp[i][j][k] = dp[i - 1][j][k];
        } else {
          dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i]];
        }
      }
    }
  }

  ll ans = 0;
  rep(j, 1, N) { ans += dp[N][j][j * A]; }

  printf("%lld\n", ans);

  return 0;
}
