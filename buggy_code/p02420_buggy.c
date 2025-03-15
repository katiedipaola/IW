#include <stdio.h>
#include <string.h>
int main(void) {
  int i, j, k, m, x;
  char n[200], n1[200];
  while (1) {
    while (scanf("%s", n) != EOF)
      ;
    if (n[0] == '-')
      break;
    x = strlen(n);
    scanf("%d", &k);
    for (m = 0; m < k; m++) {
      scanf("%d", &i);
      strncpy(n1, n, i);
      n1[i] = '\0';
      for (j = 0; j < x - i; j++)
        n[j] = n[i + j];
      n[j] = '\0';
      strcat(n, n1);
    }
    printf("%s\n", n);
  }
  return 0;
}