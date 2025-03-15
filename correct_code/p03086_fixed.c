#include <stdio.h>
int main(void) {
  int i, m = 0, v = 0;
  char s[11];
  scanf("%s\n", s);
  for (i = 0; i <= 11; i++) {
    if ((s[i] == 'A') || (s[i] == 'T') || (s[i] == 'C') || (s[i] == 'G')) {
      m++;
    } else {
      m = 0;
    }
    if (v <= m)
      v = m;
  }
  printf("%d\n", v);
  return 0;
}
