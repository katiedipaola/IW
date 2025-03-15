#include <stdio.h>
#include <string.h>
int main() {
  char a[102];
  char b[102];
  int c;

  scanf("%s", a);
  fflush(stdin);
  scanf("%s", b);
  fflush(stdin);
  c = strlen(a);
  for (int i = 0; i < c; i++) {
    if (b[i] == NULL) {
      printf("%c", a[i]);
    } else {
      printf("%c%c", a[i], b[i]);
    }
  }
  return 0;
}