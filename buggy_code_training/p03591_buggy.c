#include <stdio.h>
int main(void) {
  int i;
  char str[256];
  scanf("%s", str);
  if (str[0] == 'y' && str[1] == 'a' && str[2] == 'k' && str[3] == 'i') {
    printf("yes");
  } else {
    printf("no");
  }
  return 0;
}