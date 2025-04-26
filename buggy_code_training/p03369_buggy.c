#include <stdio.h>

int main() {
  int a = 0, i;
  char S;

  for (i = 0; i < 3; i++) {
    scanf("%c", &S);
    if (S == '○') {
      a += 100;
    }
  }

  printf("%d\n", 700 + a);

  return 0;
}