U;
i;
j;
w[9 << 14];
main(k) {
  for (; ~scanf("%d", &k);)
    j++ &&w[k]++;
  for (; ++i < 1e5;)
    U = fmax(w[--i] + w[++i] + w[i + 1], U);
  printf("%d", U);
}