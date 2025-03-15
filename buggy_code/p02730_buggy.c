#include <stdio.h>

int main() {
  int i, n = 0, m = 1;
  char s[100];
  scanf("%s", &s);
  while (s[n] != 0)
    n++;
  for (i = 0; (i < n / 2) && (m != 0); i++) {
    if (s[n - i - 1] != s[i])
      m = 0;
  }
  for (i = 0; (i < (n - 1) / 4) && (m != 0); i++) {
    if (s[(n - 1) / 2 - i - 1] != s[i])
      m = 0;
  }
  for (i = (n + 3) / 2 - 1; (i < (n + 1) * 3 / 4) && (m != 0); i++) {
    if (s[n + 2 - i] != s[i])
      m = 0;
  }
  if (m == 1) {
    printf("Yes");
  } else {
    printf("No");
  }
  return (0);
}
