#include <stdio.h>
#include <string.h>
int main(void) {
  int i, j, flag;
  flag = 0;
  char s[100000];
  scanf("%s", s);
  i = strlen(s);
  if (s[0] == s[i]) {
    if (i % 2 == 1)
      printf("Second");
    else
      printf("First");
  } else {
    if (i % 2 == 1)
      printf("First");
    else
      printf("Second");
  }
  return 0;
}