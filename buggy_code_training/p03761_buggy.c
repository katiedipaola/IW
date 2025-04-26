#include <stdio.h>
#include <string.h>
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  char s[55][55];
  for (i = 0; i < n; i++)
    scanf("%s", s[i]);
  int c[30];
  for (i = 0; i < n; i++)
    c[i] = 100;
  int p[30];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 30; j++)
      p[j] = 0;
    for (j = 0; j < strlen(s[i]); j++)
      p[(int)(s[i][j] - 'a')]++;
    for (j = 0; j < 30; j++)
      c[j] = min(c[j], p[j]);
  }
  for (i = 0; i < 30; i++)
    if (c[i] > 0)
      for (j = 0; j < c[i]; j++)
        printf("%c", 'a' + i);
  printf("\n");
  return 0;
}