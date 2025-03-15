s[9];
i;
main(c) {
  for (scanf("%*d%d", &c); ~scanf("%s", s); i++)
    strcmp(s, "snuke") || printf("%c%d", i % c + 65, i / c + 1);
}