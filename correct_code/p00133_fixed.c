#include <stdio.h>

int main(void) {
  int i, j;
  char pat[8][8];
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      scanf("%c", &pat[i][j]);
    }
    getchar();
  }
  printf("90\n");
  for (i = 0; i < 8; i++) {
    for (j = 7; j >= 0; j--) {
      printf("%c", pat[j][i]);
    }
    printf("\n");
  }
  printf("180\n");
  for (i = 7; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      printf("%c", pat[i][j]);
    }
    printf("\n");
  }
  printf("270\n");
  for (i = 7; i >= 0; i--) {
    for (j = 0; j < 8; j++) {
      printf("%c", pat[j][i]);
    }
    printf("\n");
  }
  return 0;
}