#include <stdio.h>
#include <string.h>
int main() {
  char word[1111];
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    gets(word);
    for (;;) {
      if (strstr(word, "Hoshino") == 0) {
        break;
      } else {
        strncpy(strstr(word, "Hoshino"), "Hoshina", 7);
      }
    }
    printf("%s\n", word);
  }
  return 0;
}