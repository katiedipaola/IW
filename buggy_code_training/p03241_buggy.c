#if 0
cat <<EOF >mistaken-paste
#endif
// thanks for @rsk0315_h4x

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
#define VERYBIG 2000000000000007LL

#define MOD 1000000007
#define FOD 998244353
typedef uint64_t ull;
typedef int64_t sll;

#define N_MAX 1000000

#ifdef __cplusplus
#include <algorithm>
#include <array>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>

using std::greater;
using std::map;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::tuple;
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
sll va, vb, vc, vd, ve, vf;
ull ua, ub, uc, ud, ue, uf;
long double vra, vrb, vrc;
double vda, vdb, vdc;
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

int bitcount(ull n) {
  int result = 0;
  while (n) {
    if (n & 1)
      result++;
    n /= 2;
  }
  return result;
}

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

int32_t pdoublecomp(const void *left, const void *right) {
  double l = *(double *)left;
  double r = *(double *)right;
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

int32_t phwllREVcomp(const void *left, const void *right) {
  hwll l = *(hwll *)left;
  hwll r = *(hwll *)right;
  if (l.b < r.b) {
    return -1;
  }
  if (l.b > r.b) {
    return +1;
  }
  if (l.a < r.a) {
    return -1;
  }
  if (l.a > r.a) {
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

int32_t ptripleREVcomp(const void *left, const void *right) {
  hwllc l = *(hwllc *)left;
  hwllc r = *(hwllc *)right;

  if (l.b < r.b) {
    return -1;
  }
  if (l.b > r.b) {
    return +1;
  }
  if (l.a < r.a) {
    return -1;
  }
  if (l.a > r.a) {
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

int32_t pquadcomp(const void *left, const void *right) {
  linell l = *(linell *)left;
  linell r = *(linell *)right;

  sll ac = phwllABcomp(&(l.a), &(r.a));
  if (ac)
    return ac;
  sll bc = phwllABcomp(&(l.b), &(r.b));
  if (bc)
    return bc;

  return 0;
}

bool isinrange(sll left, sll x, sll right) { return (left <= x && x <= right); }

bool isinrange_soft(sll left, sll x, sll right) {
  return (left <= x && x <= right) || (left >= x && x >= right);
}

sll a[N_MAX];
// ull a[N_MAX];
// sll a[3001][3001];
sll b[N_MAX];
// sll b[3001][3001];
sll c[N_MAX];
// sll d[N_MAX];
// sll e[N_MAX];
char s[N_MAX + 1];
// char s[3010][3010];
char t[N_MAX + 1];
// char t[3010][3010];
hwll xy[N_MAX];
hwllc tup[N_MAX];
// sll table[1000][1000];

ull solve() {
  sll i, j, ki, li;
  ull result = 0;
  // sll result = 0;
  double dresult = 0;
  // ull maybe = 0;
  sll maybe = 0;
  // ull sum = 0;
  sll sum = 0;
  sll item;
  ull *dpcell;

  ull downer = 1;
  for (i = 1; i * i <= m; i++) {
    if (m % i)
      continue;

    if ((m / i) * n <= m) {
      result = m / i;
    }
    if (i * n <= m) {
      downer = i;
    }
  }
  if (!result)
    result = downer;

  printf("%lld\n", result);
  // printf("%.15lf\n", dresult);
  // puts(s);

  return 0;

success:
  // puts("YES");
  puts("Yes");
  // printf("%llu\n", result);
  // puts("0");
  // puts("Yay!");
  return 0;

fail:
  // puts("NO");
  puts("No");
  // puts("0");
  // puts("-1");
  // puts("-1 -1 -1");
  // puts("Impossible");
  return 1;
}

int32_t main(void) {
  int32_t i, j;
  int32_t x, y;

  // scanf("%llu%llu", &h, &w);
  scanf("%llu%llu", &n, &m);
  // scanf("%llu", &k, &n, &m);
  // scanf("%llu%llu", &h, &w);
  // scanf("%lld%lld", &va, &vb, &vc, &vd);
  // scanf("%llu%llu", &ua, &ub, &uc, &ud);
  // scanf("%llu", &q);
  // scanf("%s", s);
  // scanf("%s", t);
  // for (i = 0; i < n; i++) {
  // 	// scanf("%lld%lld", &xy[i].a, &xy[i].b);
  // 	// scanf("%lld%lld%lld", &tup[i].a, &tup[i].b, &tup[i].c);
  // 	scanf("%lld", &a[i]);
  // 	scanf("%lld", &b[i]);
  // 	scanf("%lld", &c[i]);
  // 	// scanf("%lld", &d[i]);
  // 	a[i]--;
  // 	b[i]--;
  // 	// c[i]--;
  // 	// tup[i].a--;
  // 	// tup[i].b--;
  // }
  // scanf("%llu", &m, &k);
  // scanf("%llu", &q);
  // scanf("%s", s);
  // for (i = 0; i < m; i++) {
  // 	scanf("%lld", &b[i]);
  // 	// b[i]--;
  // }

  // for (i = 0; i < h; i++) {
  // 	for (j = 0; j < w; j++) {
  // 		scanf("%llu", &table[i][j]);
  // 	}
  // }
  // for (i = 0; i < h; i++) {
  // 	scanf("%s", &s[i]);
  // }

  solve();

  return 0;
}
