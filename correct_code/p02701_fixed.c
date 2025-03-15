#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int n, i;
  char s[200001][11];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", &s[i]);
  }
  qsort(s, n, 11, strcmp);
  int count = 1;
  for (i = 1; i < n; i++) {
    if (strcmp(s[i], s[i - 1]) != 0) {
      count++;
    }
  }
  printf("%d", count);
  return 0;
}
