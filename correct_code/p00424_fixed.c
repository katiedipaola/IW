#include <stdio.h>

char conv[10000];
char ans[100000005];

int main(void) {
  int i, j, n, m;
  char c, a, b;

  while (1) {
    scanf("%d", &n);

    if (n == 0)
      break;

    for (i = 0; i < 10000; i++)
      conv[i] = 0;

    for (i = 0; i < n; i++) {
      scanf(" %c %c", &a, &b);
      conv[a] = b;
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {

      scanf(" %c", &c);
      if (conv[c] != 0) {
        ans[i] = conv[c];
      } else {
        ans[i] = c;
      }
    }
    ans[i] = '\0';

    printf("%s\n", ans);
  }
  return (0);
}
