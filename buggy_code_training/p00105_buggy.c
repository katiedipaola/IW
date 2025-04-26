#include <stdio.h>
#include <string.h>
typedef struct {
  int page;
  char name[50];
} STR;
main() {
  STR temp, str[10000];
  int i, j, k;
  int count = 0;
  while (scanf("%s %d", str[i].name, &str[i].page) != EOF) {
    i++;
  }
  for (j = 0; j < i; j++) {
    for (k = i - 1; 0 < k; k--) {
      if (strcmp(str[k].name, str[k - 1].name) < 0) {
        temp = str[k];
        str[k] = str[k - 1];
        str[k - 1] = temp;
      } else if (strcmp(str[k].name, str[k - 1].name) == 0) {
        if (str[k].page < str[k - 1].page) {
          temp = str[k];
          str[k] = str[k - 1];
          str[k - 1] = temp;
        }
      }
    }
  }
  for (j = 0; j < i; j++) {
    if (j != 0) {
      if (strcmp(str[j].name, str[j - 1].name) == 0) {
        printf(" %d", str[j].page);
      } else {
        printf("\n%s\n%d", str[j].name, str[j].page);
      }
    } else {
      printf("%s\n%d", str[j].name, str[j].page);
    }
  }
  printf("\n");
  return 0;
}
