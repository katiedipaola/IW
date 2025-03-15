#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  char s[100005];
  scanf("%s", s);
  for (int count = 0; s[count] != '\0'; count++) {
    if (count % 2 == 0) {
      printf("%c", s[count]);
    }
  }
}