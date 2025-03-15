char s[65536], t[65536];
int main(n, i, r, w, c) {
  for (; scanf("%d", &n), n; puts(s))
    for (i = !scanf("%s", s); i++ < n; t[w] = 0, strcpy(s, t))
      for (r = w = 0; r < strlen(s); t[w++] = s[r], r += c) {
        for (c = 0; s[++c + r] == s[r];)
          ;
        for (sprintf(t + w, "%d\0", c); t[++w];)
          ;
      }
  exit(0);
}