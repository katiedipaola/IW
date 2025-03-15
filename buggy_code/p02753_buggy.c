#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char s[4] = {0};
  scanf("%s", s);
  if (strcmp(s, "aaa") == 0 || strcmp(s, "bbb") == 0) {
    printf("No");
  } else {
    printf("Yes");
  }
  return 0;
}