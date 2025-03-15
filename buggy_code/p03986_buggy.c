#include <stdio.h>

char str[200005];
int ch;
int sp = 0;

int main() {

  while ((ch = getchar()) != EOF) {

    if (ch == 's') {
      sp++;
      str[sp] = 's';
    } else if (ch == 't') {
      if (str[sp] == 's') {
        sp--;
      } else {
        sp++;
        str[sp] = 't';
      }
    }
  }

  printf("%d\n", sp);

  return 0;
}
