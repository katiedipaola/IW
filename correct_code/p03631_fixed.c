#include <stdio.h>
#include <string.h>

int main() {
  char s[3];
  scanf("%s", s);

  if (s[0] == s[2]) {
    printf("%s", "Yes");
  } else {
    printf("%s", "No");
  }

  return 0;
}
