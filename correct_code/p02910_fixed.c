#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int i = 1;
  char c = '0';
  while (1) {
    c = getchar();
    if (c == '\n' || c == EOF)
      break;
    if (i % 2 == 0 && c == 'R') {
      printf("No");
      return 0;
    } else if (i % 2 == 1 && c == 'L') {
      printf("No");
      return 0;
    }
    i++;
  }
  printf("Yes");
  return 0;
}
