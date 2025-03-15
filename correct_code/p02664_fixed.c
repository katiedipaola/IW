#include <stdio.h>
#include <string.h>

int main() {
  char t[300000];
  scanf("%s", t);

  int len = strlen(t);

  for (int i = 0; i < len; i++) {
    if (t[i] == '?') {
      t[i] = 'D';
    }
  }

  printf("%s", t);
  return 0;
}