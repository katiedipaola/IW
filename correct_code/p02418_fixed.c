#include <stdio.h>
#include <string.h>
int main(void) {
  int i, len;
  char s[4096], p[4096], s2[4096];
  scanf("%s", s);
  scanf("%s", p);
  sprintf(s2, "%s%s", s, s);
  puts(strstr(s2, p) == NULL ? "No" : "Yes");
  return 0;
}
