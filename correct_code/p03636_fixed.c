#include <stdio.h>
#include <string.h>

int main(void) {
  char S[110];
  int length;
  scanf("%s", S);
  length = strlen(S);
  printf("%c%d%c\n", S[0], length - 2, S[length - 1]);
  return 0;
}
