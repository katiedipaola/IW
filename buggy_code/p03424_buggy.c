#include <stdio.h>
#include <stdlib.h>

int main() {
  int x, i;
  char c;
  int flag;
  scanf("%d", &x);

  for (i = 0; i < x; i++) {
    scanf("%c", &c);
    if (c == 'Y')
      flag = 1;
  }

  flag ? printf("Four\n") : printf("Three\n");

  return 0;
}
