#include <stdio.h>
#include <string.h>
int main(void) {
  char s[26];
  int i, j, k = 0;
  scanf("%s", s);
  for (i = 0; i < strlen(s); i++) {
    for (j = 0; j < strlen(s); j++) {
      if (s[i] == s[j]) {
        if (i == j)
          k += 0;
        else
          k++;
      } else
        k += 0;
    }
  }
  if (k == 0)
    printf("yes\n");
  else
    printf("no\n");
  return 0;
}