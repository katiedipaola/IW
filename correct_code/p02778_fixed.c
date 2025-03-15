#include <stdio.h>
#include <string.h>

int main(void) {
  char s[9999], t[9999];
  int a, i;

  scanf("%s", s);

  a = strlen(s);

  for (i = 0; i < a; i++) {
    t[i] = 'x';
  }

  printf("%s", t);

  return 0;
}