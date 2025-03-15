#include <math.h>
#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += k)
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
#define MOD 1000000007

ll dp
    [10010][110]
    [2]; // dp[i][j][k]=上からi桁目まで決まっていて、modがjで、Nより小さいことが確定して(k?いる:いない)
char s[10010];

int main() {
  ll d;
  scanf("%lld %s", &d, s);
  ll n = strlen(s);
  dp[0][0][0] = 1;
  rep(i, 0, n) rep(j, 0, d) {
    rep(dig, 0, 10) dp[i + 1][(j + dig) % d][1] =
        (dp[i + 1][(j + dig) % d][1] + dp[i][j][1]) % MOD;
    rep(dig, 0, s[i] - '0') dp[i + 1][(j + dig) % d][1] =
        (dp[i + 1][(j + dig) % d][1] + dp[i][j][0]) % MOD;
    dp[i + 1][(j + s[i] - '0') % d][0] =
        (dp[i + 1][(j + s[i] - '0') % d][0] + dp[i][j][0]) % MOD;
  }
  printf("%lld\n", (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD);
  return 0;
}