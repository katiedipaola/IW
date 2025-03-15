#include <stdio.h>
#include <string.h>

int main(void) {
  int b, i, j, x, y = 0, z = 0;
  char a[101][11];
  scanf("%d", &b);
  for (i = 0; i < b; i++) {
    scanf("%s", a[i]);
  }
  for (i = 0; i < b; i++) {
    for (j = 0; j < b; j++) {
      if (strcmp(a[i], a[j]) == 0) {
        y++;
      }
    }
  }
  for (i = 0; i < b - 1; i++) {
    x = strlen(a[i]);
    if (a[i][x - 1] != a[i + 1][0]) {
      z = 1;
    }
  }
  if (y == b) {
    if (z == 0) {
      printf("Yes");
    } else {
      printf("N");
    }
  } else {
    printf("No");
  }
  return 0;
}