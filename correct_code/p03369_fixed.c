#include <stdio.h>

int main() {
  int a = 700, i;
  char S;

  for (i = 0; i < 3; i++) {
    scanf("%c", &S);
    if (S == 'o') {
      a += 100;
    }
  }

  printf("%d\n", a);

  return 0;
}