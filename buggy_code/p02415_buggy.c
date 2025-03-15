#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char c[1200];
  int i, len;
  scanf("%[^\n]", c);

  len = sizeof(c);

  for (i = 0; i < len; i++) {
    if (isupper(c)) {
      c[i] = tolower(c[i]);
    } else {
      c[i] = toupper(c[i]);
    }
  }

  printf("%s", c);

  return 0;
}
