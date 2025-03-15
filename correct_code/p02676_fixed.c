#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int k = 0;
  char l[200];
  char s[200];
  int i;

  fgets(l, sizeof(l), stdin);
  k = atoi(l);
  // printf("%d", k);

  fgets(s, sizeof(s), stdin);
  // printf("%d", strlen(s));

  if (strlen(s) - 1 <= k) {
    printf("%s", s);
  } else {
    for (i = 0; i < k; i++)
      printf("%c", s[i]);
    printf("...");
  }

  return 0;
}