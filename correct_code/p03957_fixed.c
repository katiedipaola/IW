#include <stdio.h>
#include <string.h>
char s[105];
int main() {
  int i, len, j;
  scanf("%s", s);
  len = strlen(s);
  if (len == 2) {
    if (s[0] == 'C' && s[1] == 'F')
      printf("Yes");
    else
      printf("No");
    return 0;
  }
  for (i = 0; i < len - 1; i++) {
    if (s[i] == 'C') {
      for (j = i + 1; j < len; j++) {
        if (s[j] == 'F') {
          printf("Yes");
          return 0;
        }
      }
    }
  }
  printf("No");
  return 0;
}