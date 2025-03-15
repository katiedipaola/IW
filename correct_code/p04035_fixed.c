#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define MOD 1000000007LL
#define STR_EQ(s1, s2) strcmp(s1, s2) == 0
#define rep(i, l, n) for (int(i) = (l); (i) < (n); (i)++)
#define invrep(i, l, n) for (int(i) = (l); (i) >= (n); (i)--)
//#define MOD 998244353LL
//#define MOD 1000000009LL
const long long INF = 1LL << 60;
typedef long long ll;
ll llabs(ll a) {
  if (a < 0)
    return -a;
  return a;
} // abs
void swap(ll *a, ll *b) {
  ll tmp = *a;
  *a = *b;
  *b = tmp;
} // swap
int fact(int a) {
  int r = 1;
  for (int i = 1; i <= a; i++)
    r *= i;
  return r;
} // factral
ll addm(ll a, ll b) {
  ll x = (a % MOD + b % MOD) % MOD;
  if (x < 0)
    x += MOD;
  return x;
} // addmod,submod
ll mulm(ll a, ll b) { return (a % MOD * b % MOD) % MOD; } // mulmod
ll lpow(ll x, ll n) {
  ll ans = 1;
  while (n) {
    if (n & 1)
      ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
} // power
ll powm(ll x, ll n) {
  x %= MOD;
  ll ans = 1;
  while (n) {
    if (n & 1)
      ans = mulm(ans, x);
    x = mulm(x, x);
    n >>= 1;
  }
  return ans;
} // power mod
ll lgcd(ll a, ll b) {
  if (a == b)
    return a;
  if (a < b)
    swap(&a, &b);
  if (b == 0)
    return a;
  return lgcd(b, a % b);
} // gcd
ll llcm(ll a, ll b) { return a * b / lgcd(a, b); }; // lcm
ll legcd(ll a, ll b, ll *x, ll *y) {
  if (b == 0) {
    *x = 1;
    y = 0;
    return a;
  }
  ll q = a / b;
  ll g = legcd(b, a - q * b, x, y);
  ll z = *x - q * (*y);
  *x = *y;
  *y = z;
  return g;
} // extra_gdd
ll divm(ll a, ll b) {
  ll x, y;
  a %= MOD;
  b %= MOD;
  legcd(b, MOD, &x, &y);
  x %= MOD;
  if (x < 0)
    x += MOD;
  return x;
} // divmod_with_extra_gdd
ll permutation(ll n, ll m) {
  if (n < m)
    return 0;
  if (n - m < m)
    m = n - m;
  int ans = 1;
  for (int i = 0; i < m; i++)
    ans *= (n - i);
  return ans;
} // nPm
ll combination(ll n, ll m) { return permutation(n, m) / m; } // nCm
int acmpinum(const void *left, const void *right) {
  if (*(int *)left > *(int *)right)
    return 1;
  else if (*(int *)left < *(int *)right)
    return -1;
  else
    return 0;
} // qsort(int配列,配列の長さ,sizeof(int),acmpinum);
int dcmpinum(const void *left, const void *right) {
  if (*(int *)left > *(int *)right)
    return -1;
  else if (*(int *)left < *(int *)right)
    return 1;
  else
    return 0;
} // qsort(int配列,配列の長さ,sizeof(int),dcmpinum);
int acmpllnum(const void *left, const void *right) {
  if (*(ll *)left > *(ll *)right)
    return 1;
  else if (*(ll *)left < *(ll *)right)
    return -1;
  else
    return 0;
} // qsort(ll配列,配列の長さ,sizeof(ll),acmpllnum);
int dcmpllnum(const void *left, const void *right) {
  if (*(ll *)left > *(ll *)right)
    return -1;
  else if (*(ll *)left < *(ll *)right)
    return 1;
  else
    return 0;
} // qsort(ll配列,配列の長さ,sizeof(ll),dcmpllnum);
int cmpchar(const void *left, const void *right) {
  char *left_char = (char *)left;
  char *right_char = (char *)right;
  return strcmp(left_char, right_char);
} // qsort(文字列配列,1,文字列の長さ,cmpchar);

int main() {
  ll N, L, left, right;
  left = 0, right = -1;
  scanf("%lld %lld", &N, &L);
  ll a[N];
  for (ll i = 0; i < N; i++)
    scanf("%lld", &a[i]);
  for (ll i = 0; i < N; i++) {
    if (a[i] >= L) {
      left = i + 1;
      right = left;
      break;
    } else if (i != N - 1) {
      if (a[i] + a[i + 1] >= L) {
        left = i + 1;
        right = i + 2;
        break;
      }
    }
  }
  if (left == 0) {
    printf("Impossible\n");
    return 0;
  }
  printf("Possible\n");
  for (ll i = 1; i < left; i++)
    printf("%lld\n", i);
  for (ll i = N - 1; i >= right; i--)
    printf("%lld\n", i);
  if (left != right)
    printf("%lld\n", left);
  return 0;
}