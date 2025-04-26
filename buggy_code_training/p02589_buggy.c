#define M '   '
char *s, T[M], *r = T;
U[M * 35];
n;
k;
main(i) {
  for (; gets(r + 1); k = !--n)
    for (; *++r &= 31;)
      U[r - T] = k |= !!n << *r;
  for (; ~i--;)
    for (s = r; s-- > T; k = U[k] = U[k -= ~-~*s * M] ?: *s ? s - T : 0)
      n += __builtin_popcount(U[s - T] & (U[k - M] ^= !s[-1] << *s));
  printf("%d\n", n + 1);
}