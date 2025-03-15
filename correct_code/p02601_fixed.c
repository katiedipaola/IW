#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef long long ll;

int int_cmp(const void *a, const void *b) {
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return *ia - *ib;
}

int max(int a, int b) {
  if (a < b)
    a = b;
  return a;
}

int min(int a, int b) {
  if (a > b)
    a = b;
  return a;
}

int absolu(int n) {
  if (n < 0)
    n *= -1;

  return n;
}

void solve() {
  int a, b, c, k;
  scanf("%d%d%d%d", &a, &b, &c, &k);

  while (k > 0) {
    if (b >= c)
      c *= 2;
    else if (a >= b)
      b *= 2;
    k--;
  }

  if (a < b && b < c)
    printf("Yes\n");
  else
    printf("No\n");
}

int main() {
  /*int t;
       scanf("%d",&t);

       while(t--)*/
  solve();

  return 0;
}
