#include <stdio.h>
int main() {
  int n, i, a = 0, b = 0;
  char s[100];

  scanf("%d", &n);
  scanf("%s", s);

  for (i = 0; i < n; i++) {
    if (s[i] == ')')
      a++;
    else if (a > 0)
      a--;
    else
      b++;
  }

  for (i = 0; i < a; i++) {
    printf("(");
  }
  printf("%s", s);
  for (i = 0; i < b; i++) {
    printf(")");
  }

  return 0;
}
