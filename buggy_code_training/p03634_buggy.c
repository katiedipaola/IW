#include <stdio.h>

#define N 100000

int oo[1 + (N - 1) * 2], oj[1 + (N - 1) * 2], ow[1 + (N - 1) * 2];

int link(int o, int j, int w) {
  static int _ = 1;

  oo[_] = o, oj[_] = j, ow[_] = w;
  return _++;
}

int ae[N];
long long dd[N];

void dfs(int p, int i, long long d) {
  int o;

  dd[i] = d;
  for (o = ae[i]; o; o = oo[o]) {
    int j = oj[o], w = ow[o];

    if (j != p)
      dfs(i, j, d + w);
  }
}

int main() {
  int n, q, k, h;

  scanf("%d", &n);
  for (h = 0; h < n - 1; h++) {
    int i, j, w;

    scanf("%d%d%d", &i, &j, &w), i--, j--;
    ae[i] = link(ae[i], j, w);
    ae[j] = link(ae[j], i, w);
  }
  scanf("%d%d", &q, &k), k--;
  dfs(-1, k, 0);
  while (q--) {
    int i, j;

    scanf("%d%d", &i, &j), i--, j--;
    printf("%d\n", dd[i] + dd[j]);
  }
  return 0;
}