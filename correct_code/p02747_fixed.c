#include <stdio.h>
#include <string.h>

int main() {
  int a;
  char s[11];
  scanf("%s", s);
  a = strlen(s);

  for (int i = 0; i <= a - 1; i += 2) {
    if (s[i] != 'h' || s[i + 1] != 'i') {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
