#include <stdio.h>
#include <string.h>
char str[100], *p;
int i;
int main() {
  for (; !strstr(p = fgets(str, 100, stdin), "END OF INPUT\n");) {
    for (i = 0; *p; i = *(p++) < 33 ? !printf("%d", i) : i + 1)
      ;
    puts("");
  }
  return 0;
}