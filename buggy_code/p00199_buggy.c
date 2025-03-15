n, m, p;
char s[2], c[101];
A() {
  for (p = 0; c[p] != '#'; p++)
    ;
}
B() {
  for (p = n - 1; p >= 0; p--)
    if (c[p] == '#' && (p + 1 == n || c[p + 1] != 'A') &&
        (p - 1 < 0 || c[p - 1] != 'A'))
      return;
  A();
}
C() {
  for (p = 0; p < n; p++) {
    if (c[p] != '#') {
      if (p + 1 != n && c[p + 1] == '#') {
        p++;
        return;
      }
      if (p - 1 >= 0 && c[p - 1] == '#') {
        p--;
        return;
      }
    }
  }
  p = n / 2;
}
D() {
  int D[100], d = n, q;
  for (p = -1; ++p < n;) {
    d++;
    if (c[p] != '#')
      d = 0;
    D[p] = d;
  }
  for (d = 0; --p >= 0;) {
    d++;
    if (c[p] != '#')
      d = 0;
    if (d < D[p])
      D[p] = d;
  }
  for (p = q = 0; q < n; q++)
    if (D[q] > D[p])
      p = q;
}
main() {
  for (; scanf("%d%d", &n, &m), n;) {
    memset(c, '#', 100);
    c[n] = 0;
    for (; m--;) {
      scanf("%s", s);
      if (s[0] == 'A')
        A();
      if (s[0] == 'B')
        B();
      if (s[0] == 'C')
        C();
      if (s[0] == 'D')
        D();
      c[p] = s[0];
    }
    puts(c);
  }
  exit(0);
}