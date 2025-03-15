#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define max(p, q) ((p) > (q) ? (p) : (q))
#define min(p, q) ((p) < (q) ? (p) : (q))
#define INF ((1LL << 62) - (1LL << 31))

ll iti[90010];
ll cost[90010];
ll h, w, d;
int main() {
  scanf("%lld%lld%lld", &h, &w, &d);
  rep(i, 0, w) rep(j, 0, h) {
    ll t;
    scanf("%lld", &t);
    iti[t] = i * 1000 + j;
  }

  rep(i, d + 1, h * w + 1) {
    cost[i] = cost[i - d] + llabs(iti[i] / 1000 - iti[i - d] / 1000) +
              llabs(iti[i] % 1000 - iti[i - d] % 1000);
  }

  ll q;
  scanf("%lld", &q);
  while (q--) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", cost[r] - cost[l]);
  }
  return 0;
}