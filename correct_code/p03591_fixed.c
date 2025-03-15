#include <stdio.h>
int main(void) {
  int i;
  char str[256];
  scanf("%s", str);
  if (str[0] == 'Y' && str[1] == 'A' && str[2] == 'K' && str[3] == 'I') {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}