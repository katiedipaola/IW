#include <stdio.h>

int main(void) {
  int n;
  char s[16];
  char new_num[8] = {0, 1, 2, 3, 5, 7, 8, 9};
  int i;

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    sprintf(s, "%o", n);
    for (i = 0; s[i] != '\0'; i++) {
      if (s[i] >= '4') {
        s[i]++;
      }
      if (s[i] >= '5') {
        s[i]++;
      }
    }
    printf("%s\n", s);
  }

  return (0);
}