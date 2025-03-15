char *c, b[999];
t, s;
main() {
  read(0, b, 999);
  for (c = strchr(b, 10); *c++; t *= !!(*c - 10))
    *c - 49 || (s = s < ++t ? t : s);
  printf("%d\n", s);
  exit(0);
}