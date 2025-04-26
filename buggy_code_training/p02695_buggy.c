#include <stdio.h>
int n, m, q, max = 0;
int A[15];
int a[55], b[55], c[55], d[55];
int check() {
  int ans = 0;
  for (int i = 1; i <= q; i++)
    if (A[b[i]] - A[a[i]] == c[i])
      ans += d[i];
  return ans;
}
void make(int i, int t) {
  if (i == t + 1) {
    int x = check();
    if (x > max)
      max = x;
    return;
  }
  for (int j = t; j <= m; j++) {
    A[i] = j;
    make(i + 1, j);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  int i = 1;
  for (; i <= q; i++)
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  make(1, 1);
  printf("%d", max);
  return 0;
}