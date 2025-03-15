#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FOR(i, a, n) for (i = (a); i < (n); i++)
#define swap(type, a, b)                                                       \
  do {                                                                         \
    type t = a;                                                                \
    a = b;                                                                     \
    b = t;                                                                     \
  } while (0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ll long long
#define INF 100000000
#define MOD 1000000007
#define SIZE 100005
#define LOCAL
#ifdef LOCAL
#define DEBUG(...) printf(" "__VA_ARGS__)
#else
#define DEBUG(...)
#endif /* LOCAL */
int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
  ll x, y, res = 0;
  scanf("%lld%lld", &x, &y);
  while (y > x)
    x <<= 1, res++;
  printf("%lld\n", res);
  return 0;
}
