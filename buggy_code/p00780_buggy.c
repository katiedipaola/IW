// 50000 for aizu0056
// 1000000 for aizu0185
#define M 32769
p[M + 1];
main(n, i, j) {
  p[1] = 1;
  for (; i <= M; i++)
    if (!p[i])
      for (j = i * 2; j <= M; j += i)
        p[j] = 1;
  for (; scanf("%d", &n), n; printf("%d\n", j))
    for (i = 2, j = 0; i <= n / 2; i++)
      if (!p[i] && !p[n - i])
        j++;
  return 0;
}