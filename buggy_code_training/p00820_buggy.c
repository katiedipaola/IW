i, z = 256, t[65536];
main(i, j, k, l, x) {
  for (; i < z; i++)
    for (j = i; j < z; j++)
      for (k = j; k < z; k++)
        for (l = k; l < z; l++) {
          if ((x = i * i + j * j + k * k + l * l) >= z * z)
            break;
          t[x]++;
        }
  while (scanf("%d", &x), x)
    printf("%d\n", t[x]);
  return 0;
}