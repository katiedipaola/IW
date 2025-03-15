#include <stdio.h>
#include <string.h>

int main() {
  char s[10001];
  int n;
  scanf("%d", &n);
  scanf("%s", s);

  int len = strlen(s);
  int a = (int)'A';
  int z = (int)'Z';
  for (int i = 0; i < len; i++) {
    int c = (int)s[i] - a;
    printf("%c", (char)((c + n) % (z - a + 1) + a));
  }
}