#define _USE_MATH_DEFINES
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EPS 1e-10
#define sq(n) ((n) * (n))
#define rep(i, n) for (i = 0; i < n; i++)
#define rev(i, n) for (i = n - 1; i >= 0; i--)
#define sort(a, n) qsort(a, n, sizeof(TYPE), cmp)
#define sort_r(a, n) qsort(a, n, sizeof(TYPE), cmp_r);
#define chsort(s, n) qsort(s, n, sizeof(char), cmp)
#define chsort_r(s, n) qsort(s, n, sizeof(char), char_cmp_r);
#define TYPE long long
#define MEMSET(a) memset(a, 0, sizeof(a))
long long mod = (long long)1e09 + 7;
int inf = 1 << 30;

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
int main(void) {
  int n = in(), k = in(), a[100000], i;
  rep(i, n) a[i] = in();
  print((n - 1) / (k - 1) + !!((n - 1) / (k - 1)));
  return 0;
}