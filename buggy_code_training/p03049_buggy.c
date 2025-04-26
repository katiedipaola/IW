#include <stdio.h>
#include <string.h>
int main() {
  int n;
  scanf("%d", &n);
  int i, j;
  char s[10004][11];
  for (i = 0; i < n; i++)
    scanf("%s", s[i]);
  int ans = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < strlen(s[i]) - 1; j++)
      if (s[i][j] == 'A' && s[i][j + 1] == 'B')
        ans++;
  int a, b, c;
  a = b = c = 0;
  for (i = 0; i < n; i++) {
    if (s[i][0] == 'B')
      b++;
    if (s[i][strlen(s[i]) - 1] == 'A')
      a++;
    if (s[i][0] == 'B' && s[i][strlen(s[i]) - 1] == 'A')
      c++;
  }
  if (a < b)
    ans += a;
  else if (a > b)
    ans += b;
  else {
    if (a == c)
      ans += a - 1;
    else
      ans += a;
  }
  printf("%d\n", ans);
  return 0;
}