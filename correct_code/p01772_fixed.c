#include <stdio.h>
#include <string.h>
int main() {
  int len, i, num = 0;
  char str[21], stack[21] = {
                    0,
                };
  scanf("%s", &str);
  len = strlen(str);
  for (i = 0; i < len; i++) {
    if (num % 2 == 0)
      if (str[i] == 'A')
        stack[num++] = 'A';
    if (num % 2 == 1)
      if (str[i] == 'Z')
        stack[num++] = 'Z';
  }
  if (num % 2 == 1)
    stack[--num] = '\0';
  if (num != 0)
    printf("%s\n", stack);
  else
    printf("-1\n");
  return 0;
}