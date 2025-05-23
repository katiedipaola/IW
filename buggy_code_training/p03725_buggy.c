/*
cat <<EOF >mistaken-paste
*/

#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
#define _USE_MATH_DEFINES

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BIG 2000000007
#define VERYBIG 200000000000007LL

#define MOD 1000000007
#define FOD 998244353
typedef uint64_t ull;
typedef int64_t sll;

#define N_MAX 300000
#define M_MAX 200000

#ifdef __cplusplus
#include <queue>
#include <stack>
// #include <tuple>
#include <map>
#include <set>

// using namespace std; // HELL
using std::priority_queue;
using std::queue;
using std::stack;
// using std::tuple;
using std::greater;
using std::map;
using std::pair;
using std::set;
using std::vector;

#endif

typedef struct {
  int32_t a;
  int32_t b;
} hw;

typedef struct {
  sll a;
  sll b;
} hwll;

typedef struct {
  sll a;
  sll b;
  sll c;
} hwllc;

typedef struct {
  hwll a;
  hwll b;
} linell;

ull n, m;
ull h, w;
ull k;
ull q;
ull vua, vub, vuc, vud, vue, vuf;
sll vsa, vsb, vsc, vsd, vse, vsf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
size_t slen;
size_t tlen;
char ch, dh;

ull umin(ull x, ull y) { return (x < y) ? x : y; }

ull umax(ull x, ull y) { return (x > y) ? x : y; }

sll smin(sll x, sll y) { return (x < y) ? x : y; }

sll smax(sll x, sll y) { return (x > y) ? x : y; }

ull gcd(ull x, ull y) {
  if (x < y) {
    return gcd(y, x);
  } else if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}

ull bitpow(ull a, ull x, ull modulo) {
  ull result = 1;
  while (x) {
    if (x & 1) {
      result *= a;
      result %= modulo;
    }
    x /= 2;
    a = (a * a) % modulo;
  }
  return result;
}

ull divide(ull a, ull b, ull modulo) {
  return (a * bitpow(b, modulo - 2, modulo)) % modulo;
}

ull udiff(ull a, ull b) {
  if (a >= b) {
    return a - b;
  } else {
    return b - a;
  }
}

sll sdiff(sll a, sll b) {
  if (a >= b) {
    return a - b;
  } else {
    return b - a;
  }
}

void printUquotient(ull left, ull right) {
  const int32_t digits = 20;

  printf("%llu.", left / right);
  left %= right;
  for (int32_t i = 0; i < digits; i++) {
    left *= 10;
    printf("%1d", left / right);
    left %= right;
  }
  puts("");

  return;
}

void printSquotient(sll left, sll right) {
  if (left * right < 0)
    putchar('-');
  printUquotient(sdiff(left, 0), sdiff(right, 0));

  return;
}

int bitcount(ull n) {
  int result = 0;
  while (n) {
    if (n & 1)
      result++;
    n /= 2;
  }
  return result;
}

#ifdef __cplusplus

bool setfind(set<ull> s, ull x) { return (s.find(x) != s.end()); }

#endif

// double distance (sll x1, sll y1, sll x2, sll y2) {
// 	double xdist2, ydist2, origindist, dist;

// 	xdist2 = (x1 - x2) * (x1 - x2);
// 	ydist2 = (y1 - y2) * (y1 - y2);
// 	return sqrt(xdist2 + ydist2);
// }

int32_t pullcomp(const void *left, const void *right) {
  ull l = *(ull *)left;
  ull r = *(ull *)right;
  if (l < r) {
    return -1;
  }
  if (l > r) {
    return +1;
  }
  return 0;
}

int32_t psllcomp(const void *left, const void *right) {
  sll l = *(sll *)left;
  sll r = *(sll *)right;
  if (l < r) {
    return -1;
  }
  if (l > r) {
    return +1;
  }
  return 0;
}

int32_t pcharcomp(const void *left, const void *right) {
  char l = *(char *)left;
  char r = *(char *)right;
  if (l < r) {
    return -1;
  }
  if (l > r) {
    return +1;
  }
  return 0;
}

int32_t pstrcomp(const void *left, const void *right) {
  char *l = *(char **)left;
  char *r = *(char **)right;

  return strcmp(l, r);
}

int32_t phwllABcomp(const void *left, const void *right) {
  hwll l = *(hwll *)left;
  hwll r = *(hwll *)right;
  if (l.a < r.a) {
    return -1;
  }
  if (l.a > r.a) {
    return +1;
  }
  if (l.b < r.b) {
    return -1;
  }
  if (l.b > r.b) {
    return +1;
  }
  return 0;
}

int32_t ptriplecomp(const void *left, const void *right) {
  hwllc l = *(hwllc *)left;
  hwllc r = *(hwllc *)right;

  if (l.a < r.a) {
    return -1;
  }
  if (l.a > r.a) {
    return +1;
  }
  if (l.b < r.b) {
    return -1;
  }
  if (l.b > r.b) {
    return +1;
  }
  if (l.c < r.c) {
    return -1;
  }
  if (l.c > r.c) {
    return +1;
  }
  return 0;
}

bool isinrange(sll left, sll x, sll right) { return (left <= x && x <= right); }

ull parent[N_MAX];
ull rank[N_MAX];
void uf_init(ull n) {
  for (sll i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}
ull uf_find(ull x) {
  if (parent[x] == x)
    return x;
  return parent[x] = uf_find(parent[x]);
}
bool uf_union(ull a, ull b) {
  a = uf_find(a);
  b = uf_find(b);
  if (a == b)
    return false;

  if (rank[a] > rank[b]) {
    parent[b] = a;
  } else {
    parent[a] = b;
    if (rank[a] == rank[b]) {
      rank[b]++;
    }
  }
  return true;
}

sll a[N_MAX];
sll b[N_MAX];
// char s[N_MAX];
char s[3010][3010];

hwllc que[1000000];
sll dp[3010][3010];

ull solve() {
  sll i, j, ki, li;
  // ull result = 0;
  sll result = 0;
  double dresult = 0;
  // ull maybe = 0;
  sll maybe = 0;
  // ull sum = 0;
  sll sum = 0;
  sll item;
  ull *dpcell;

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      dp[i][j] = BIG;
    }
  }

  ull qbeg = 0, qend = 0;
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
        hwllc x = {i, j, k};
        que[qend++] = x;
        dp[i][j] = k;
        break;
      }
    }
  }

  result = BIG;
  while (qbeg < qend) {
    sll ci = que[qbeg].a;
    sll cj = que[qbeg].b;
    sll ck = que[qbeg].c;
    qbeg++;

    maybe = umin(umin(ci, h - 1 - ci), umin(cj, w - 1 - cj));
    result = umin(result, maybe);

    hwll vec[4] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    for (i = 0; i < 4; i++) {
      sll ni = ci + vec[i].a;
      sll nj = cj + vec[i].b;

      if (0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] != '#') {
        sll nk = ck - 1;
        if (nk >= 0 && dp[ni][nj] < nk) {
          hwllc x = {ni, nj, nk};
          que[qend++] = x;
          dp[ni][nj] = nk;
        }
      }
    }
  }

  result = (result ? (result - 1) / k + 1 : 0) + 1;

  printf("%lld\n", result);
  // printf("%.12lf\n", dresult);
  // puts(s);

  return 0;

success:
  // puts("YES");
  // puts("Yes");
  // printf("%llu\n", result);
  // puts("0");
  puts("Takahashi");
  return 0;

fail:
  // puts("NO");
  // puts("No");
  // puts("0");
  // puts("-1");
  // puts("-1 -1 -1");
  puts("Aoki");
  return 1;
}

int32_t main(void) {
  int32_t i, j;
  int32_t x, y;

  // scanf("%lf%lf", &vda, &vdb, &vdc);
  // scanf("%lld%lld", &vsa, &vsb, &vsc, &vsd);
  // scanf("%llu%llu%llu", &vua, &vub, &vuc, &vud);
  scanf("%llu%llu", &h, &w);
  // scanf("%*llu%*llu");
  // scanf("%llu", &n, &m);
  scanf("%llu", &k, &n);
  // scanf("%llu%llu%llu", &vua, &vub, &vuc, &vud, &vue, &vuf);
  // vua--;
  // vub--;
  // scanf("%lld%lld", &vsa, &vsb, &vsc);
  // scanf("%s", s);
  // scanf("%s", t);
  // scanf("%llu", &k);
  // scanf("%llu", &q);
  // for (i = 0; i < n; i++) {
  // 	scanf("%lld", &a[i]);
  // 	scanf("%lld", &b[i]);
  // 	// scanf("%llu", &c[i]);
  // 	// a[i]--;
  // 	// b[i]--;
  // 	// c[i]--;
  // }
  // scanf("%llu", &q);

  // for (i = 0; i < h; i++) {
  // 	for (j = 0; j < w; j++) {
  // 		scanf("%llu", &a[i][j]);
  // 	}
  // }
  for (i = 0; i < h; i++) {
    scanf("%s", &s[i]);
  }

  // scanf("%llu", &k);
  // scanf("%llu", &q);
  solve();

  return 0;
}
