#include <stdio.h>
int seg[1200006], ss;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void set(int x, int v) {
  x += ss - 1;
  seg[x] = v;
  while (x > 0) {
    x = (x - 1) / 2;
    seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
  }
  return;
}
int get(int l, int r) {
  l += ss - 1;
  r += ss - 1;
  int res = 0;
  while (l < r) {
    if (l % 2 == 0)
      res = max(res, seg[l]);
    l /= 2;
    if (r % 2 > 0)
      res = max(res, seg[r]);
    r = r / 2 - 1;
  }
  if (l == r)
    res = max(res, seg[l]);
  return res;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int i;
  int a[300005];
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  ss = 1;
  while (ss < 300005)
    ss *= 2;
  for (i = 0; i < 2 * ss - 1; i++)
    seg[i] = 0;
  for (i = 0; i < n; i++)
    set(a[i], get(max(a[i] - k, 0), min(a[i] + k, ss - 1)) + 1);
  printf("%d\n", seg[0]);
  return 0;
}