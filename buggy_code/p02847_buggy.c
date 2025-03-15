#include <stdio.h>
#include <string.h>

int main() {
  char input[4];
  char *list[7] = {"SUN", "MON", "THU", "WED", "THU", "FRI", "SAT"};
  int I = 0;
  scanf("%s", input);
  // printf("%s\n",input);
  for (int i = 0; i < 7; i++) {
    // printf("%s\n",list[i]);
    if (!strcmp(input, list[i])) {
      I = i;
      break;
    }
  }

  printf("%d\n", 7 - I);
}
