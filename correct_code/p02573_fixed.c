#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, l, r) for (ll i = l; i < (ll)(r); i++)
#define max(l, r) ((l) > (r) ? l : r)
#define min(l, r) ((l) < (r) ? l : r)
#define swap(l, r)                                                             \
  {                                                                            \
    ll tp = l;                                                                 \
    l = r;                                                                     \
    r = tp;                                                                    \
  }
const ll MOD = 1000000007;

/////Union Find(for C)/////
int par[201010]; // par:-1*(size of set), chi:par
void UF(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = -1;
  }
}
int root(int x) {
  if (par[x] < 0)
    return x;
  return par[x] = root(par[x]);
}
void unite(int x, int y) {
  int rx = root(x);
  int ry = root(y);
  if (rx == ry)
    return;
  if (par[rx] > par[ry])
    swap(rx, ry);
  par[rx] += par[ry];
  par[ry] = rx;
}
int same(int x, int y) { return (root(x) == root(y) ? 1 : 0); }
int size(int x) { return (-par[root(x)]); }
/////----------/////

int main() {
  int n, m, flag = 0;
  scanf("%d%d", &n, &m);
  UF(n);
  rep(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if (same(a, b) == 0)
      unite(a, b);
  }
  int ans = 1;
  rep(i, n) { ans = max(size(i), ans); }

  printf("%d\n", ans);
}