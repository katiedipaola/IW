#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int n, m, x, y;
  int max = -1000;
  int min = 1000;
  scanf("%d %d %d %d\n", &n, &m, &x, &y);
  char str[10240];
  char *ptr;
  fgets(str, sizeof(str), stdin);
  fflush(stdin);

  ptr = strtok(str, " ");
  while (ptr != NULL) {
    if (max <= atoi(ptr)) {
      max = atoi(ptr);
    }
    ptr = strtok(NULL, " ");
  }

  int str_len = strlen(str);
  memset(str, '\0', str_len);

  fgets(str, sizeof(str), stdin);
  fflush(stdin);

  ptr = strtok(str, " ");
  while (ptr != NULL) {
    if (min >= atoi(ptr)) {
      min = atoi(ptr);
    }
    ptr = strtok(NULL, " ");
  }

  if ((max < min && max < y) && (x < min && x < y)) {
    printf("No War\n");
  } else {
    printf("War\n");
  }

  return 0;
}