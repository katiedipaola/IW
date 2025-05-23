#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf (INT_MAX - 1)
#define INF 9223372036854775807
#define sq(n) ((n) * (n))
#define rep(i, n) for (i = 0; i < n; i++)
#define rev(i, n) for (i = n - 1; i >= 0; i--)
#define sort(a, n) qsort(a, n, sizeof(TYPE), cmp)
#define sort_r(a, n) qsort(a, n, sizeof(TYPE), cmp_r);
#define chsort(s, n) qsort(s, n, sizeof(char), cmp)
#define chsort_r(s, n) qsort(s, n, sizeof(char), char_cmp_r);
#define TYPE long long
#define MEMSET(a) memset(a, 0, sizeof(a))
const int mod = (int)1e09 + 7;

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
long long llabs(long long a) { return a > 0 ? a : -a; }
double dmax(double a, double b) { return a > b ? a : b; }
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
struct list {
  int a;
  struct list *prev;
  struct list *next;
};
struct list *head, *tail;
struct list *make(int a) {
  struct list *p;
  p = malloc(sizeof(struct list));
  p->a = a;
  p->prev = NULL;
  p->next = NULL;
  return p;
}

int g[8][8];
int mark[8];
int n;

int dfs(int i) {
  int j, ret = 0;
  mark[i] = 1;
  rep(j, n) if (!mark[j]) break;
  if (j == n)
    return 1;
  rep(j, n) {
    if (g[i][j] && !mark[j]) {
      ret += dfs(j);
      mark[j] = 0;
    }
  }
  return ret;
}

int main(void) {
  int m, i, a, b;
  n = in();
  m = in();
  rep(i, n) {
    a = in();
    b = in();
    a--;
    b--;
    g[a][b] = g[b][a] = 1;
  }
  print(dfs(0));
  return 0;
}