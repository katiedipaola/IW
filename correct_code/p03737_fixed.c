#include <stdio.h>
int main(void) {
  char str[100];
  int i;
  for (i = 0; i < 3; ++i) {
    scanf("%s", str + i);
    str[i] &= 0xdf;
  }
  str[i] = '\0';
  printf("%s\n", str);
  return 0;
}
