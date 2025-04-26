U;
i;
j;
w[9 << 14];
main(k) {
  for (; ~scanf("%d", &k);)
    j++ &&w[k]++;
  for (; i < 1e5;)
    U = fmax(w[--i] + w[++i] + w[i++], U);
  printf("%d", U);
}