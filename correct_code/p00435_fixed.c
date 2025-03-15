#include <stdio.h>
int main() {
  int x[26] = {'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
               'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'};
  char input[1001];
  int i;
  scanf("%s", input);
  char c = input[0];
  for (i = 0; (c != '\0'); i++) {
    printf("%c", x[(c - 65)]);
    c = input[i + 1];
  }
  putchar('\n');
  return 0;
}