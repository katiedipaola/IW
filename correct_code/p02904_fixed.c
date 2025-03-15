#include <stdio.h>
int segmin[1000006], segmax[1000006];
int m;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int getmin(int l, int r) {
  int res = 1000000009;
  l += m - 1;
  r += m - 1;
  while (l < r) {
    if (l % 2 == 0) {
      res = min(res, segmin[l]);
      l++;
    }
    if (r % 2 > 0) {
      res = min(res, segmin[r]);
      r--;
    }
    l = (l - 1) / 2;
    r = (r - 1) / 2;
  }
  if (l == r)
    res = min(res, segmin[l]);
  return res;
}
int getmax(int l, int r) {
  int res = -1;
  l += m - 1;
  r += m - 1;
  while (l < r) {
    if (l % 2 == 0) {
      res = max(res, segmax[l]);
      l++;
    }
    if (r % 2 > 0) {
      res = max(res, segmax[r]);
      r--;
    }
    l = (l - 1) / 2;
    r = (r - 1) / 2;
  }
  if (l == r)
    res = max(res, segmax[l]);
  return res;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int i;
  int p[200005];
  for (i = 0; i < n; i++)
    scanf("%d", &p[i]);
  int s[200005];
  s[0] = 1;
  for (i = 1; i < n; i++) {
    if (p[i - 1] < p[i])
      s[i] = s[i - 1] + 1;
    else
      s[i] = 1;
  }
  m = 1;
  while (m < n)
    m *= 2;
  for (i = 0; i < 2 * m - 1; i++)
    segmin[i] = n;
  for (i = 0; i < n; i++)
    segmin[i + m - 1] = p[i];
  for (i = m - 2; i >= 0; i--)
    segmin[i] = min(segmin[2 * i + 1], segmin[2 * i + 2]);
  for (i = 0; i < 2 * m - 1; i++)
    segmax[i] = -1;
  for (i = 0; i < n; i++)
    segmax[i + m - 1] = p[i];
  for (i = m - 2; i >= 0; i--)
    segmax[i] = max(segmax[2 * i + 1], segmax[2 * i + 2]);
  int ans = 0;
  for (i = 0; i < n; i++)
    if (s[i] >= k)
      ans = 1;
  if (s[k - 1] < k)
    ans++;
  for (i = 0; i < n - k; i++)
    if (s[i + k] < k)
      if (p[i] != getmin(i, i + k) || p[i + k] != getmax(i, i + k))
        ans++;
  printf("%d\n", ans);
  return 0;
}