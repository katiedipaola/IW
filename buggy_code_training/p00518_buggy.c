int a, z, u, i, j, k, d[1999][9];
main() {
  scanf("%d ", &a);
  d[0][2] = 1;
  for (i = 0; i < a; i++) {
    u = getchar() % 4 - 1;
    for (j = 8; j--;) {
      for (k = 8; k--;)
        if (j & k && j >> u & 1)
          d[i + 1][j] += d[i][k] % 10007;
      z += d[a][j];
    }
  }
  printf("%d\n", u % 10007);
}