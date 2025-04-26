#include <stdio.h>
int MAX(int a, int b) { return a < b ? b : a; }
int main() {
  char s[20];
  int max = 0, l, i, a = 0;
  scanf("%s", s);
  for (l = 0; s[l]; l++)
    ;
  for (i = 0; i < l; i++) {
    max = MAX(max, a + (s[i] - '0' - 1) + (l - i - 1) * 9);
    a += s[i] - '0';
  }
  printf("%d\n", max);
  return 0;
}
