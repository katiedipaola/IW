#include <stdio.h>
int main() {
  char str[5];
  scanf("%s", str);
  char t = str[0];
  for (int i = 1; i < 4; i++) {
    char t2 = str[i];
    if (t == t2) {
      printf("Bad\n");
      return 0;
    }
    t = t2;
  }
  printf("Good\n");
  return 0;
}
