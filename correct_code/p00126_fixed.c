m[9][9];
x[9][9];
z[10];
main(n, i, j) {
  for (scanf("%d", &n); n--; n ? puts("") : 1, memset(x, 0, 324)) {
    for (i = 0; i < 9; i++)
      for (j = 0; j < 9; j++)
        scanf("%d", m[i] + j);
    for (i = 0; i < 9; i++) {
      memset(z, 0, 40);
      for (j = 0; j < 9; j++)
        z[m[i][j]]++;
      for (j = 0; j < 9; j++)
        if (z[m[i][j]] > 1)
          x[i][j] = 1;
    }
    for (i = 0; i < 9; i++) {
      memset(z, 0, 40);
      for (j = 0; j < 9; j++)
        z[m[j][i]]++;
      for (j = 0; j < 9; j++)
        if (z[m[j][i]] > 1)
          x[j][i] = 1;
    }
    for (i = 0; i < 9; i++) {
      memset(z, 0, 40);
      for (j = 0; j < 9; j++)
        z[m[i % 3 * 3 + j / 3][i / 3 * 3 + j % 3]]++;
      for (j = 0; j < 9; j++)
        if (z[m[i % 3 * 3 + j / 3][i / 3 * 3 + j % 3]] > 1)
          x[i % 3 * 3 + j / 3][i / 3 * 3 + j % 3] = 1;
    }
    for (i = 0; i < 9; puts(""), i++)
      for (j = 0; j < 9; j++)
        printf(x[i][j] ? "*%d" : " %d", m[i][j]);
  }
  exit(0);
}