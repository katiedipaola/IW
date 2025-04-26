#include <stdio.h>
int main(void) {
  char s[120];
  int n;
  int b = 0, r = 0, count;
  scanf("%d", &n);
  scanf("%d", s);
  for (count = 0; s[count] != '\0'; count++) {
    if (s[count] == 'B') {
      b++;
    }
    if (s[count] == 'R') {
      r++;
    }
  }
  if (r > b) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}