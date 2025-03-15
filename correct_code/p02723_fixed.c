#include <stdio.h>
int main(void) {
  // Your code here!
  char s[6];
  scanf("%s", s);
  if (s[2] == s[3] && s[4] == s[5]) {
    printf("Yes");
  } else
    printf("No");
  return 0;
}
