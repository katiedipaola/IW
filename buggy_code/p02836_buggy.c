#include <stdio.h>
#include <string.h>
int main(void) {
  char s[105];
  int i, j = 0, k;
  scanf("%s", s);
  k = strlen(s);
  for (i = 0; i < k; i++) {
    if (s[i] != s[k - 1 - i])
      j++;
  }
  printf("%d\n", j);
  return 0;
}