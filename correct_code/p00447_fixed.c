a[200], b[200], c[1000], d[1000], n, m, i, j, k, t, w, q;
main() {
  for (;;) {
    scanf("%d", &n);
    if (!n)
      break;
    for (i = 0; i < n; i++)
      scanf("%d%d", &a[i], &b[i]);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
      scanf("%d%d", &c[i], &d[i]);
    }
    for (i = 0; i < m; i++) {
      w = c[i] - a[0];
      q = d[i] - b[0];
      for (j = 1; j < n; j++) {
        for (k = 0; k < m; k++) {
          if (a[j] + w == c[k]) {
            if (b[j] + q == d[k]) {
              t++;
              break;
            }
          }
        }
      }
      if (t == n - 1) {
        printf("%d %d\n", w, q);
        t = 0;
        break;
      }
      t = 0;
    }
  }
  return 0;
}