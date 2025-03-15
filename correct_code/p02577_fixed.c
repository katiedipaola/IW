#include <stdio.h>
#include <stdlib.h>
char s[200002];
char ss;
long int ans;

long int getSN(char ss) {
  if (ss == '0')
    return 0;
  else if (ss == '1')
    return 1;
  else if (ss == '2')
    return 2;
  else if (ss == '3')
    return 3;
  else if (ss == '4')
    return 4;
  else if (ss == '5')
    return 5;
  else if (ss == '6')
    return 6;
  else if (ss == '7')
    return 7;
  else if (ss == '8')
    return 8;
  else if (ss == '9')
    return 9;
  else
    return 0;
}

int main(void) {
  scanf("%s", s);

  for (int j = 0; s[j] != '\0'; j++) {
    int n = getSN(s[j]);
    ans = (ans + n) % 9;
  }
  if (ans == 0)
    printf("Yes");
  else
    printf("No");

  return 0;
}