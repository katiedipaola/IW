m[10][2], x[10][2], z[10][2], zz[10][2];
rotx[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
roty[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
mov[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
main(N, M, Z, t, i, j, k, mxm, mym, mxM, myM, zxm, zym, zxM, zyM) {
  for (; scanf("%d", &N), N; puts("+++++")) {
    /*input zero*/
    zxm = zym = 9999, zxM = zyM = -9999;
    for (scanf("%d", &Z), i = 0; i < Z; i++) {
      scanf("%d%d", z[i], z[i] + 1);
      if (zxm > z[i][0])
        zxm = z[i][0];
      if (zym > z[i][1])
        zym = z[i][1];
      if (zxM < z[i][0])
        zxM = z[i][0];
      if (zyM < z[i][1])
        zyM = z[i][1];
    }
    for (i = 0; i < Z; i++)
      z[i][0] -= zxm, z[i][1] -= zym, zz[Z - 1 - i][0] = z[i][0],
                                                 zz[Z - 1 - i][0] = z[i][1];
    zxM -= zxm, zyM -= zym;
    for (j = 0; j < N; j++) {
      /*input line*/
      mxm = mym = 9999, mxM = myM = -9999;
      for (scanf("%d", &M), i = 0; i < M; i++) {
        scanf("%d%d", m[i], m[i] + 1);
        if (mxm > m[i][0])
          mxm = m[i][0];
        if (mym > m[i][1])
          mym = m[i][1];
        if (mxM < m[i][0])
          mxM = m[i][0];
        if (myM < m[i][1])
          myM = m[i][1];
      }
      for (i = 0; i < M; i++)
        m[i][0] -= mxm, m[i][1] -= mym;
      mxM -= mxm, myM -= mym;
      if (M != Z)
        continue;
      mov[1][0] = myM, mov[2][0] = mxM, mov[2][1] = myM, mov[3][1] = mxM;
      /*compare*/
      for (k = 0; k < 4; k++) {
        for (i = 0; i < M; i++)
          x[i][0] = rotx[k][0] * m[i][0] + rotx[k][1] * m[i][1] + mov[k][0],
          x[i][1] = roty[k][0] * m[i][0] + roty[k][1] * m[i][1] + mov[k][1];
        if (!memcmp(x, z, 4 * 2 * M) || !memcmp(x, zz, 4 * 2 * M))
          printf("%d\n", j + 1), k = 4;
      }
    }
  }
  return 0;
}