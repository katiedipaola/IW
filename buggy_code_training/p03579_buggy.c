#include <stdio.h>
int ta[100010], nt[200010], to[200010], co[200010];
void mkls(int v, int e, int *a, int *b, int *c) {
  int i;
  for (i = 0; i < v; i++)
    ta[i + 1] = -1;
  for (i = 0; i < e; i++) {
    nt[i] = ta[to[i + e] = a[i]];
    nt[i + e] = ta[to[i] = b[i]];
    co[ta[b[i]] = i + e] = co[ta[a[i]] = i] = c[i];
  }
}
int main() {
  int n, m, d[100010], i, r, t, a[100010], b[100010], c[100010], q[100010];
  long long ev = 0, od = 0, ans;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    d[i + 1] = -1;
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a[i], &b[i]);
    c[i] = 1;
  }
  mkls(n, m, a, b, c);
  q[t = 0] = 1;
  d[1] = 0;
  for (r = 1; r - t; t++) {
    for (i = ta[q[t]]; i + 1; i = nt[i]) {
      if (d[to[i]] == -1) {
        d[to[i]] = d[q[t]] + 1;
        q[r++] = to[i];
      } else if (d[q[t]] % 2 == d[to[i]])
        goto END;
    }
  }
END:;
  if (r == t) {
    for (i = 0; i < n; i++) {
      if (d[i + 1] % 2)
        od++;
      else
        ev++;
    }
    ans = od * ev; // printf("no\n");
  } else
    ans = n * (n - 1LL) / 2;
  printf("%lld\n", ans - m);
  return 0;
}
