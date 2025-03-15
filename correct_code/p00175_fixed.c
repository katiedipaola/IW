#include <stdio.h>
#include <string.h>

int main(void) {
  int n;
  int i;
  int flag;
  char temp[8];

  while (1) {
    scanf("%d", &n);
    if (n == -1)
      break;

    if (n == 0) {
      puts("0");
      continue;
    }

    i = 0;
    while (n) {
      temp[i] = n % 4 + '0';
      n /= 4;
      i++;
    }

    for (; i > 0; i--) {
      putchar(temp[i - 1]);
    }

    putchar('\n');
  }

  return 0;
}