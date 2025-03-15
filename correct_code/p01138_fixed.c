#define _USE_MATH_DEFINES
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 100000000
#define INF 9223372036854775807
#define EPS 1e-10
#define sq(n) ((n) * (n))
#define rep(i, n) for (i = 0; i < n; i++)
#define rev(i, n) for (i = n - 1; i >= 0; i--)
#define sort(a, n) qsort(a, n, sizeof(TYPE), cmp)
#define sort_r(a, n) qsort(a, n, sizeof(TYPE), cmp_r);
#define chsort(s, n) qsort(s, n, sizeof(char), cmp)
#define chsort_r(s, n) qsort(s, n, sizeof(char), char_cmp_r);
#define TYPE int
#define MEMSET(a) memset(a, 0, sizeof(a))
int mod = (int)1e09 + 7;

int in(void) {
  int i;
  scanf("%d", &i);
  return i;
}
long long llin(void) {
  long long i;
  scanf("%lld", &i);
  return i;
}
double din(void) {
  double i;
  scanf("%lf", &i);
  return i;
}
void chin(char s[]) { scanf("%s", s); }
void print(int a) { printf("%d\n", a); }
void llprint(long long a) { printf("%lld\n", a); }
void dprint(double a) { printf("%.10f\n", a); }
void print2(int a, int b) { printf("%d %d\n", a, b); }
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }
int char_cmp(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}
int char_cmp_r(const void *a, const void *b) {
  return strcmp((char *)b, (char *)a);
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
long long gcd(long long x, long long y) { return x % y ? gcd(y, x % y) : y; }
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }

// write codes below this
// when you use 'sort',
// make sure TYPE macro is correct
int y[24 * 3600];

int main(void) {
  int n, sh, sm, ss, th, tm, ts, i, s, t, ans;
  while ((n = in())) {
    MEMSET(y);
    ans = 0;
    rep(i, n) {
      scanf("%d:%d:%d", &sh, &sm, &ss);
      scanf("%d:%d:%d", &th, &tm, &ts);
      s = sh * 3600 + sm * 60 + ss;
      t = th * 3600 + tm * 60 + ts;
      y[s]++;
      y[t]--;
    }
    for (i = 1; i < 24 * 3600; i++)
      y[i] += y[i - 1];
    rep(i, 24 * 3600) ans = max(ans, y[i]);
    print(ans);
  }
  return 0;
}
