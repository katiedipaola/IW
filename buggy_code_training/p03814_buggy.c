int main(void) {
  int i, j, n;
  char s[20001];
  scanf("%s", s);
  for (n = 0; s[n] != '\0'; n++)
    ;
  for (i = 1; s[i] != 'A'; i++)
    ;
  for (j = 1; s[n - j] != 'Z'; j++)
    ;
  printf("%d\n", n - i - j);
  return 0;
}