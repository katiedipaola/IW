t[99], h[99];
main(i, s, N, T, L) {
  for (scanf("%d%d%d%d", &N, &T, &L, &L), i = 0; i++ < N;)
    scanf("%d%d", t + i, h + i);
  for (i = s = 0;; i = (i + 1) % N)
    if (t[i]) {
      t[i]--;
      if (++T > L)
        break;
      if (++s == 9)
        s = 0;
    } else if (h[i]) {
      h[i]--;
      s++;
      if (T < s)
        break;
      t[i] = s;
      T -= s;
      s = 0;
    } else
      break;
  printf("%d\n", i + 1);
  exit(0);
}