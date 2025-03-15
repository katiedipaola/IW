#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char s[27];
  scanf("%s", s);
  int i, j, len = strlen(s), memo[26] = {0};
  if (len < 26) {
    for (i = 0; i < len; i++)
      memo[(s[i] - 'a')] = 1;
    for (i = 0; memo[i]; i++) {
      s[len] = 'a' + i;
      s[len + 1] = '\0';
      printf("%s", s);
      return 0;
    }
  } else {
    for (i = len - 1; i >= 0; i--) {
      memo[s[i] - 'a'] = 1;
      for (j = s[i] - 'a' + 1; j < 26 && !memo[j]; j++)
        ;
      if (j < 26) {
        s[i] = 'a' + j;
        s[i + 1] = '\0';
        printf("%s", s);
        return 0;
      }
    }
  }
  printf("-1");
  return 0;
}