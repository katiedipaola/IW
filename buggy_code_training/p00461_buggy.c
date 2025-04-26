main(n, s, c, d) {
  for (; scanf("%d%d ", &n) * n; printf("%d\n", s))
    for (s = c = 0; d = getchar() - 10; s += c % 2 & c / 2 >= n)
      c = d - 63 ? c % 2 ? c + 1 : 0 : c % 2 ?: c + 1;
}