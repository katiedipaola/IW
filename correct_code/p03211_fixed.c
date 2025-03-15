#include <stdio.h>
#include <string.h>

int main() {
  char s[11];
  int i, j, d;

  scanf("%s", s);
  d = 999;
  for (i = 0; i < strlen(s) - 2; i++) {
    j = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
    if (abs(753 - j) < d)
      d = abs(753 - j);
  }
  printf("%d\n", d);
  return 0;
}
