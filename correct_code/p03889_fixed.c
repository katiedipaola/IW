#include <stdio.h>
#include <string.h>

int main() {
  int i, l;
  char s[131072] = {0}, t[131072] = {0};
  scanf("%s", s);
  l = strlen(s);
  for (i = 0; i < l; i++) {
    t[l - i - 1] = s[i];
  }
  for (i = 0; i < l; i++) {
    if (t[i] == 'b') {
      t[i] = 'd';
    } else if (t[i] == 'd') {
      t[i] = 'b';
    } else if (t[i] == 'p') {
      t[i] = 'q';
    } else if (t[i] == 'q') {
      t[i] = 'p';
    }
  }
  if (strcmp(s, t) == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}