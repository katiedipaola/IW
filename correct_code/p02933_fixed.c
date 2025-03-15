#include <stdio.h>

int main(void) {
  int a;
  char str[10];

  scanf("%d%s", &a, str);

  if (a >= 3200)
    printf("%s", str);
  else {
    printf("red");
  }

  return 0;
}