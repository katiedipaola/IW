#include <stdio.h>

int main(void) {
  char s[80];
  char t[80];
  int i;
  scanf("%s", &s);
  scanf("%s", &t);

  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] != t[i]) {
      printf("No\n");
      return (0);
    }
  }
  if (t[i + 2] != '\0') {
    printf("Yes\n");
  } else
    printf("No\n");
  return (0);
}