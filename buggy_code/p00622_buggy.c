char r[99], g[99], *G, d[99];
main(c, i, k) {
  for (; scanf("%s%s%s", r, g, d) > 1; puts(""))
    for (i = k = 0, G = g, c = *G++; *G;)
      c == d[k] ? k++, c = r[i++] : (putchar(c), c = *G++);
  exit(0);
}