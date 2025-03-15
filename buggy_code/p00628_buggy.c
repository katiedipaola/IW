#include <stdio.h>
#include <string.h>
char str[100], *p;
int i;
int main() {
  for (; !strstr(p = gets(str), "END OF INPUT");) {
    for (i = 0; *p; i = *(p++) < 33 ? !printf("%d", i) : i + 1)
      ;
    puts("");
  }
  return 0;
}