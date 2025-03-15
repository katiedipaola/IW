#include <stdio.h>

int main() {
  char s[11];
  int i;
  scanf("%s", s);

  for (i = 0; i < 10; i++) {
    if (i != 3) {
      printf("%c", s[i]);
    } else {
      printf("8");
    }
  }
  printf("\n");
  return 0;
}
