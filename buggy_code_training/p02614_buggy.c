#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long LL;
typedef long double Lf;
#define Rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define rep(i, n) Rep(i, 0, n)
#define Ma(x, y) ((x) > (y) ? (x) : (y))
#define mi(x, y) ((x) < (y) ? (x) : (y))
#define MOD 1000000007
int acs(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
} // 1,2,3,4
int des(const void *a, const void *b) {
  return *(int *)b - *(int *)a;
} // 8,7,6,5
int cmp_char(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
} // a,b,c,d
int cmp_str(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
} // aaa,aab
// snippet
#define N 100009

int main() {
  int h, w, k, masu[7][7] = {0};
  LL ans = 0;
  char s[7];
  scanf("%d%d%d", &h, &w, &k);
  rep(i, h) {
    scanf("%s", s);
    rep(j, w) {
      if (s[j] == '#')
        masu[i][j] = 1;
    }
  }

  rep(allh, 1 << h) rep(allw, 1 << w) {
    int tmp = 0, masur[7][7] = {0};
    rep(i, h) if (allh & (1 << i)) { rep(j, w) masur[i][j]++; }
    rep(j, w) if (allw & (1 << j)) { rep(i, w) masur[i][j]++; }
    /*rep(i, h) {
            rep(j, w)printf("%d", masur[i][j]);
            printf("\n");
    }*/
    rep(i, h) rep(j, w) if (masu[i][j] == 1 && masur[i][j] == 0) tmp++;
    if (tmp == k)
      ans++;
  }
  printf("%lld", ans);

  return 0;
}