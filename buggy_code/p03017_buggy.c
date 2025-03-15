///

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
int upcmpll(const void *a, const void *b) {
  return (*(ll *)a == *(ll *)b ? 0 : (*(ll *)a > *(ll *)b ? 1 : -1));
}
void sort_u(ll *a, int n) { qsort(a, n, sizeof(ll), upcmpll); }

int main() {
  int n, a, b, c, d;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  char s[201010];
  scanf("%s", s);

  int ok = 1;
  REP(i, a - 1, d) {
    if (s[i] == s[i + 1] && s[i] == '#') {
      ok = 0;
    }
  }
  if (c > d && ok) {
    ok = 0;
    REP(i, b - 1, d + 1) {
      if (s[i] == s[i + 1] && s[i] == s[i - 1] && s[i] == '.') {
        ok = 1;
      }
    }
  }
  if (ok)
    puts("Yes");
  else
    puts("No");
}
