#include <stdio.h>
#include <string.h>
int main() {
  char a[10], b[10];
  scanf("%c %c", &a, &b);
  if ((a[0] == b[2]) && (a[1] == b[1]) && (a[2] == b[0]))
    printf("YES");
  else
    printf("NO");

  return 0;
}
