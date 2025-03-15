f = 0, n, i, a[100010];
long p = 1, ans = 0, b[100010] = {0};
#define rep(x) for (i = 0; i <= x; i++)
main() {
  scanf("%d", &n);
  rep(n) scanf("%d", &a[i]);
  rep(n - 1) b[n - 1 - i] = b[n - i] + a[n - i];
  rep(n) {
    ans += p;
    p -= a[i];
    if (p < 0)
      break;
    p <<= 1;
    p = (p > b[i] ? b[i] : p);
  }
  if (i <= n)
    printf("-1");
  else
    printf("%ld", ans);
}
