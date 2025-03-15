#include <stdio.h>
int main() {
  char a;
  while (1) {
    int b = 0;
    while (1) {
      scanf("%c", &a);
      if (a == '0' && b == 0)
        return 0;
      if (a == '\n')
        break;
      b += (a - '0');
    }
    printf("%d\n", b);
  }
  return 0;
}