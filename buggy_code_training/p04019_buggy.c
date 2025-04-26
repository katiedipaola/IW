#include <stdio.h>

int main() {
  char str[1005];
  int i, j, n = 0, w = 0, s = 0, e = 0, N = 0;
  scanf("%s", str);
  for (i = 0; str[i] != '\0'; i++)
    N++;
  for (j = 0; j < N; j++) {
    if (str[j] == 'N')
      n++;
    if (str[j] == 'S')
      s++;
    if (str[j] == 'W')
      w++;
    if (str[j] == 'E')
      e++;
  }

  if (((n > 0 && s > 0) || n == s) && ((e > 0 && w > 0) || e == w))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}