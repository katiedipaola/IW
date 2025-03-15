#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int i, n, all, j;
  char *x;

  char str2[100];
  int t[50];
  scanf("%d", &n);

  char *pstr[5]; /* 1. */
  char str[100]; /* 2. */

  for (i = 0; i < n; i++) {
    scanf("%s %d", str, &t[i]);
    pstr[i] = (char *)malloc(sizeof(char) * (strlen(str) + 1)); /* 4. */
    strcpy(pstr[i], str);
  }

  scanf("%s", str2);

  x = (char *)malloc(sizeof(char) * (strlen(str2) + 1));
  strcpy(x, str2);

  all = 0;

  for (i = 0; i < n; i++) {
    if (strcmp(pstr[i], x) == 0) {
      for (j = i + 1; j < n; j++) {
        all = t[j] + all;
      }
    }
  }
  printf("%d", all);
}
