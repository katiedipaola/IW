#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, a, b, i;

  scanf("%d %d %d", &n, &a, &b);
  char *s = (char *)malloc(n * sizeof(char));

  scanf("%s", s);

  int aco = 0, bco = 0;

  for (i = 0; i < n; i++) {
    if (s[i] == 'a') {
      if (aco + bco < a + b) {
        printf("Yes\n");
        aco++;
      } else
        printf("No\n");
    } else if (s[i] == 'b') {
      if (aco + bco < a + b && bco < b) {
        printf("Yes\n");
        bco++;
      } else
        printf("No\n");
    } else
      printf("No\n");
  }
  free(s);

  return 0;
}