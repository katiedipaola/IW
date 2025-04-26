#include <stdlib.h>
#include <string.h>

#define ll long long
#define INF 1 << 31 - 1
#define LNF 9223372036854775807
#define PI 3.14159265358979
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define FOR(i, a, n) for (i = a; i < n; i++)
#define MOD 1000000007
//#define MOD 998244353
#define NUM 200010

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
int abs(int a) {
  if (a < 0)
    return -a;
  return a;
}
int dup(int a, int d) {
  if (a % d == 0)
    return a / d;
  else
    return a / d + 1;
}
int mod(int a, int m) {
  if (a < 0)
    return a % m + m;
  else
    return a % m;
}

void swapl(ll *a, ll *b) {
  ll tmp = *a;
  *a = *b;
  *b = tmp;
}
ll absl(ll a) {
  if (a < 0)
    return -a;
  return a;
}
ll dupl(ll a, ll d) {
  if (a % d == 0)
    return a / d;
  else
    return a / d + 1;
}
ll modl(ll a, ll m) {
  if (a < 0)
    return a % m + m;
  else
    return a % m;
}

ll GCD(ll a, ll b) {
  ll c = 1, tmp = MAX(a, b);
  b = MIN(a, b);
  a = tmp;
  while (c != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

ll factorial(ll n, ll m) { return n < m ? 1 : n * factorial(n - 1, m); }

int upll(const void *a, const void *b) {
  return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0;
}
int downll(const void *a, const void *b) {
  return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0;
}
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

ll dp[100001];

ll llpow(ll a, ll b) { // a^b
  if (b == 0)
    return 1;

  if ((b & 1) == 0)
    return llpow(a * a, b / 2);
  else
    return a * llpow(a, b - 1);
}

int main() {
  ll N, K;
  ll tmp;
  ll ans = 0;

  scanf("%lld%lld", &N, &K);

  dp[K] = 1;

  for (ll x = K - 1; x > 0; x--) {
    tmp = llpow(K / x, N);
    for (ll j = 2; x * j <= K; j++) {
      tmp = (MOD - dp[x * j] + tmp) % MOD;
    }
    dp[x] = tmp;
  }

  for (ll i = 1; i <= K; i++) {
    ans = (ans + i * dp[i] % MOD) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
