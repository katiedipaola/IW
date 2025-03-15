#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, num;
  char a[3];

  if (scanf("%s", a) != 1)
    exit(0);
  num = strlen(a);

  if (num == 2) {
    printf("%s\n", a);
  } else if (num == 3) {
    for (i = 0; i < num; i++) {
      printf("%c", a[num - i - 1]);
    }
    printf("\n");
  }
  return 0;
}