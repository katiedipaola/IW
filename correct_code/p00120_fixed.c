#define N 12
double M[N][1 << N], r, t;
D[N], n;
double dfs(p, f) {
  if (M[p][f] < 0) {
    int i = 0;
    M[p][f] = 0;
    for (; i < n; i++) {
      if (f & 1 << i)
        continue;
      if (t = dfs(i, f | 1 << i) + D[p] + D[i] - 2 * sqrt(D[p] * D[i] * 1.0),
          M[p][f] < t)
        M[p][f] = t;
    }
  }
  return M[p][f];
}
main(l, i, j, d) {
  for (; ~scanf("%d", &l);) {
    d = n = 0;
    do {
      scanf("%d", D + n);
      d += D[n++] * 2;
    } while (getchar() != '\n');
    for (i = 0; i < N; i++)
      for (j = 0; j < 1 << N; j++)
        M[i][j] = -1;
    for (r = i = 0; i < n; i++)
      if (t = dfs(i, 1 << i), r < t)
        r = t;
    puts(d - r < l + 1e-5 ? "OK" : "NA");
  }
  exit(0);
}