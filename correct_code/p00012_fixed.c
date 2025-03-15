main() {
  float d, e, f, g, h, i, m, n, o, p, q;
  for (; ~scanf("%f%f%f%f%f%f%f%f", &d, &e, &f, &g, &h, &i, &m, &n); puts(
           ((f - d) * (n - e) - (m - d) * (g - e)) * p > 0 && p * q > 0 ? "YES"
                                                                        : "NO"))
    p = (h - f) * (n - g) - (m - f) * (i - g),
    q = (d - h) * (n - i) - (m - h) * (e - i);
  return 0;
}