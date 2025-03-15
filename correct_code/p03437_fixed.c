#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

  char str[1000];
  char *tok;
  int x, y;

  fgets(str, sizeof(str), stdin);
  tok = strtok(str, " ");
  x = strtol(tok, NULL, 10);
  tok = strtok(NULL, " ");
  y = strtol(tok, NULL, 10);
  if (x % y == 0) {
    printf("-1");
  } else {
    printf("%d", x);
  }

  return 0;
}