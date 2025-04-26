char s[9];
x, l;
int P(a) {
  sprintf(s, "%d", a), l = strlen(s);
  for (x = 0; x < l; x++)
    if (s[x] != s[l - x - 1])
      return 0;
  return 1;
}
main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0;; i++) {
    if (!P(n - i)) {
      printf("%d\n", n - i);
      return 0;
    }
    if (!P(n + i)) {
      printf("%d\n", n + i);
      return 0;
    }
  }
  exit(0);
}