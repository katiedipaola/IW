#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  char moji[1001];
  char word[10];
  int i, a = 0;

  scanf("%s", &word);

  for (i = 0; i < 10; i++) {
    word[i] = tolower(word[i]);
  }

  while (1) {
    scanf("%s", &moji);
    if (strcmp(moji, "END_OF_TEXT") == 0) {
      break;
    }

    for (i = 0; i < 1001; i++) {
      moji[i] = tolower(moji[i]);
    }
    if (strcmp(word, moji) == 0)
      a++;
  }

  printf("%d\n", a);

  return 0;
}