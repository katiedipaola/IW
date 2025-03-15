char s[9999], t[1001];
main(i, j, m, r) {
  scanf("%s", &s);
  for (i = j = 0; i < strlen(s);) {
    if (s[i] == 'e')
      t[j++] = 'e', i += 3;
    else
      t[j++] = 'c', i += 7;
  }
  t[j] = 0;
  for (m = i = 0; i < strlen(t);) {
    for (j = i + 1; j < strlen(t); j++)
      if (t[j] == t[i])
        break;
    if (m < j - i)
      m = j - i, r = t[j - 1];
    i = j;
  }
  puts(r == 'c' ? "chicken" : "egg");
  exit(0);
}