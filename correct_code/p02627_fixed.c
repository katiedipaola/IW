#include <stdio.h>

int main(void) {

  int i;
  char moji;

  scanf("%c", &moji);

  if ((moji >= 'a') && (moji <= 'z')) {
    printf("a\n");
  } else if ((moji >= 'A') && (moji <= 'Z')) {
    printf("A\n");
  }
  return 0;
}
