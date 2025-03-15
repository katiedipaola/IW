#include <stdio.h>
#include <string.h>

int main(void) {
  char str[300], head[300], tail[300];
  int len, i;

  fgets(str, 300, stdin);
  len = strlen(str);

  if (len % 2)
    len = len - 3;
  else
    len = len - 2;

  while (len >= 0) {
    for (i = 0; i < len / 2; i++)
      head[i] = str[i];
    head[i] = '\0';

    for (i = 0; i < len / 2; i++)
      tail[i] = str[len / 2 + i];
    tail[i] = '\0';

    if (strcmp(head, tail) == 0) {
      printf("%d\n", len / 2);
      return 0;
    }
    len = len - 2;
  }

  return 0;
}
