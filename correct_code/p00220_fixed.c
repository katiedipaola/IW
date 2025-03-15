n;
char s[14];
C(i) {
  s[8] = 46;
  for (i = 12; i--;)
    s[i + (i > 7)] = 48 + (n >> (11 - i)) % 2;
}
main() {
  double d;
  for (; ~scanf("%lf", &d); d < 0 || puts(d - n / 16. ? "NA" : s))
    C(n = d * 16);
}