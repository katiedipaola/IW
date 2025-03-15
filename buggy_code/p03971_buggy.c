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
        printf("YES\n");
        aco++;
      } else
        printf("NO\n");
    } else if (s[i] == 'b') {
      if (aco + bco < a + b && bco < b) {
        printf("YES\n");
        bco++;
      } else
        printf("NO\n");
    } else
      printf("NO\n");
  }
  free(s);

  return 0;
}