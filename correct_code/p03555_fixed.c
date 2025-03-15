#include <stdio.h>
#include <string.h>
int main() {
  char a[4], b[4];
  scanf("%s %s", &a, &b);
  if ((a[0] == b[2]) && (a[1] == b[1]) && (a[2] == b[0]))
    printf("YES");
  else
    printf("NO");

  return 0;
}
