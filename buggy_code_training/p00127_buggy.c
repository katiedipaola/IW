#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
char code[300], mes[150];
char encode[6][5] = {{'a', 'b', 'c', 'd', 'e'}, {'f', 'g', 'h', 'i', 'j'},
                     {'k', 'l', 'm', 'n', 'o'}, {'p', 'q', 'r', 's', 't'},
                     {'u', 'v', 'w', 'x', 'y'}, {'z', '.', '?', '!', ' '}};

int main() {
  while (fgets(code, 300, stdin) != NULL) {
    code[strlen(code) - 1] = '\0';
    if (strlen(code) % 2 != 0)
      printf("NA\n");
    else {
      for (i = 0; i < (signed)strlen(code); i += 2) {
        if (code[i] - '1' < 0 || code[i] - '1' > 6 || code[i + 1] - '1' < 0 ||
            code[i + 1] - '1' > 5) {
          i = 999;
          printf("NA\n");
        } else
          mes[i / 2] = encode[code[i] - '1'][code[i + 1] - '1'];
      }
      if (i < 999) {
        mes[i / 2] = '\0';
        printf("%s\n", mes);
      }
    }
  }
  return 0;
}