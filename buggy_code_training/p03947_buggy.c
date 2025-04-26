#include <stdio.h>
#include <string.h>
int main() {
  char a[100000] = {0};
  int num = 0, i, n;
  scanf("%s", a);
  for (i = 0; i < strlen(a) - 1; i++) {
    if (a[i] != a[i + 1])
      num++;
  }
  printf("%d", num - 1);
  return 0;
}