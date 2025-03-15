#include <stdio.h>
#include <string.h>

int main() {
  char a[101], b[101], c[201];
  int i, j = 0, count = 0;
  scanf("%s\n%s", &a, &b);
  for (i = 0; i < strlen(a); i++) {
    c[i] = a[i];
  }
  for (i = 0; i < strlen(a); i++) {
    c[i + strlen(a)] = a[i];
  }

  if (strstr(c, b) != NULL)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
