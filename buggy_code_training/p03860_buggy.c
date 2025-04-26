#include <stdio.h>
#include <string.h>

int main() {

  char str[117];

  scanf("%s", str);
  int i;
  for (i = 0; i < 117; i++) {
    if (str[i] == " ") {
      printf("A%cC", str[i + 1]);
      return 0;
    }
  }

  return 0;
}
