#include <stdio.h>
int par[100001]; //親
int siz[100000]; //サイズ

void ini(int n) { //初期化
  for (int i = 0; i <= n; i++) {
    par[i] = i;
    siz[i] = 1;
  }
}
int root(int x) { //根を返す
  if (par[x] == x)
    return x;
  else
    return par[x] = root(par[x]);
}

void uni(int x, int y) { //くっつける
  x = root(x);
  y = root(y);
  if (x != y) {
    siz[x] += siz[y];
    par[y] = x;
  }
}

int same(int x, int y) { return root(x) == root(y); }

int size(int x) { //サイズを返す
  return siz[root(x)];
}

int main(void) {
  int i, n, m, x, y, count = 0;
  scanf("%d %d", &n, &m);
  int p[n + 1];
  ini(n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    uni(x, y);
  }
  for (i = 1; i <= n; i++) {
    if (same(i, p[i]))
      count++;
  }
  printf("%d", count);
  return 0;
}