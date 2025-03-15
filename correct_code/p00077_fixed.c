main(i, j) {
  char s[256];
  for (; ~scanf("%s", s);) {
    for (i = 0; s[i]; i++) {
      if (s[i] == '@') {
        for (j = 0; j < s[i + 1] - '0'; j++)
          putchar(s[i + 2]);
        i += 2;
      } else
        putchar(s[i]);
    }
    puts("");
  }
  exit(0);
}