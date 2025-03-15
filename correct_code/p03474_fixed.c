#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < n; i++)

int main(void) {

  int a, b;
  char s[10];
  scanf("%d %d %s", &a, &b, s);

  if (strlen(s) != a + b + 1 || s[a] != '-') {
    printf("No\n");
  } else {
    REP(i, a + b + 1) {
      if (i != a && s[i] == '-') {
        printf("No\n");
        return 0;
      }
    }
    printf("Yes\n");
  }

  return 0;
}