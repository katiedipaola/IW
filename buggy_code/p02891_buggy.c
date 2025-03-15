#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
#define chmax(a, b) ((a) = (a) > (b) ? (a) : (b))
#define chmin(a, b) ((a) = (a) < (b) ? (a) : (b))
#define abs(p) ((p) >= (0) ? (p) : (-(p)))
#define MOD 1000000007
ll power(ll a, ll b) {
  ll r = 1;
  rep(i, b) { r *= a; }
  return r;
}
#define swap(a, b)                                                             \
  do {                                                                         \
    ll w = (a);                                                                \
    (a) = (b);                                                                 \
    (b) = w;                                                                   \
  } while (0)
#define swapd(a, b)                                                            \
  do {                                                                         \
    double w = (a);                                                            \
    (a) = (b);                                                                 \
    (b) = w                                                                    \
  } while (0)

// your code here!

int main(void) {
  char S[110];
  ll K, ans = 0;
  scanf("%s %lld", S, &K);
  ll N = strlen(S);
  if (N == 1) {
    printf("%lld\n", K / 2);
    return 0;
  }
  ll f = 1, idx = 0;
  while (f && S[++idx] != '\0')
    f &= (S[idx] == S[idx - 1]);
  if (f) {
    printf("%llf\n", N * K / 2);
    return 0;
  }
  for (ll i = 0; i < N - 1;) {
    if (S[i] == S[i + 1]) {
      ll t = i, a = 1;
      while (t < N - 1 && S[t] == S[t + 1]) {
        t++;
        a++;
      }
      i = t;
      ans += a / 2;
    } else
      i++;
  }
  if (N > 2 && S[0] == S[N - 1]) {
    ll l = 1, r = 1;
    while (l < N && S[l - 1] == S[l])
      l++;
    while (r < N && S[N - r - 1] == S[N - r])
      r++;
    if (l == r && l % 2) {
      printf("%lld\n", ans * K + K - 1);
      return 0;
    }
  }
  printf("%lld\n", ans * K);
  return 0;
}
