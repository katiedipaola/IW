#include <stdio.h>

int main(void) {
  char s[4], t[4];
  int i, n;

  scanf("%s%s", s, t);
  i = 0;
  n = 0;
  while (s[i] != '\0') {
    if (s[i] == t[i]) {
      n++;
    }
    i++;
  }
  printf("%d\n", n);
  return 0;
}