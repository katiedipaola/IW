#include <stdio.h>
int main() {
  char a, b, c;
  c = 'D';
  scanf("%c %c", &a, &b);
  if (a == 'H')
    if (b == 'H')
      c = 'H';
  if (a == 'D')
    if (b == 'D')
      c = 'H';
  printf("%c\n", c);
  return 0;
}
