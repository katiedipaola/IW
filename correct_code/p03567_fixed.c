#include <stdio.h>

int main() {
  int c, i;
  char str[6];
  for (i = 0; (c = getchar()) != '\n'; i++) {
    str[i] = c;
  }

  for (int j = 0; j < i; j++) {
    if (str[j] == 'A' && str[j + 1] == 'C') {
      printf("Yes\n");
      return 0;
    }
  }

  printf("No\n");
  return 0;
}
