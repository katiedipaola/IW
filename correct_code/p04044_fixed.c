#include <stdio.h>
#include <string.h>
int main(void) {
  int n, l, i, j;
  char s[100][101], c[101];
  scanf("%d %d", &n, &l);
  for (i = 0; i < n; i++)
    scanf("%s", s[i]);
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--) {
      if (strcmp(s[j - 1], s[j]) > 0) {
        strcpy(c, s[j - 1]);
        strcpy(s[j - 1], s[j]);
        strcpy(s[j], c);
      }
    }
  }
  for (i = 0; i < n; i++)
    printf("%s", s[i]);
  putchar('\n');
  return (0);
}