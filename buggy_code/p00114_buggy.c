int G(x, y) { return y ? G(y, x % y) : x; }
#define L(x, y) ((long long)x / G(x, y) * y)
n[3], a[3], m[3];
main(i, x) {
  for (; scanf("%d%d%d%d%d%d", a, m, a + 1, m + 1, a + 2, m + 2), *m;
       n[0] *= n[1] / G(n[0], n[1]),
       printf("%d\n", n[2] / G(n[0], n[2]) * n[0]))
    for (i = 3; i--;)
      for (x = n[i] = 1; (x = a[i] * x % m[i]) > 1; n[i]++)
        ;
}