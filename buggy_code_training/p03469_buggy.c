#include <stdio.h>

int main() {
  char s[11];
  int i;
  scanf("%s", s);

  for (i = 0; i < 10; i++) {
    if (i != 3) {
      printf("%c", s[i]);
    } else {
      printf("1");
    }
  }
  printf("\0");
  return 0;
}