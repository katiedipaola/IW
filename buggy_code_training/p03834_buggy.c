#include <stdio.h>
int main() {
  int s[20];
  scanf("%s", s);
  s[5] = ' ';
  s[13] = ' ';
  printf("%s\n", s);

  return 0;
}