#include <stdio.h>
#include <string.h>

int main() {
  char str[101];
  long len;
  int counter = 0;
  int a = 0;
  int i;
  char j;
  while (scanf("%s", str) != EOF) {
    counter = 0;
    len = strlen(str);
    for (i = 0; i < len; i++) {
      j = str[len - 1 - i];
      if (j != str[i]) {
        counter++;
      }
    }
    if (counter == 0) {
      a++;
    }
  }
  printf("%d\n", a);
  return 0;
}