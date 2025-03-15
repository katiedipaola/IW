#include <stdio.h>
void main() {
  char s[101], t[101];
  int n, i;
  scanf("%d %c %c", &n, s, t);
  for (i = 0; i < n; i++) {
    printf("%c %c", s[i], t[i]);
  }
}