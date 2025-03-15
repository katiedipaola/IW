#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {

  char str[100];
  int len, i;

  scanf("%s", &str);

  len = strlen(str);

  for (i = 0; i <= len - 9; i++) {
    printf("%s", str[i]);
  }

  printf("\n");

  return 0;
}
