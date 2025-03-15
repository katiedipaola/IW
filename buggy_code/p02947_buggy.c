#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main(void) {
  int n;
  unsigned long count = 0;

  scanf("%d", &n);
  char s[n][11];

  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    qsort((void *)s[i], 10, sizeof(char), compare);
  }

  qsort((void *)s, n, sizeof(s[0]), compare);

  int tmp = 0;
  for (int i = 1; i < n; i++) {
    if (strcmp(s[i - 1], s[i]) == 0) {
      tmp++;
    } else {
      count += tmp * (tmp + 1) / 2;
      tmp = 0;
    }
  }

  count += tmp * (tmp + 1) / 2;

  printf("%lu\n", count);

  return 0;
}