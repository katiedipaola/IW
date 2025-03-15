main(a, b, c) {
  scanf("%d%d%d", &a, &b, &c);
  puts((b - a) * (b - a) < (c - a) * (c - a) ? "A" : "B");
}