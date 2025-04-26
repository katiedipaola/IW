#include <stdio.h>
#include <string.h>
int main() {
  int n, K[10000], i, j;
  char S[10000];
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &K[i]);
    }
    scanf("%s", S);

    for (i = 0; i < strlen(S); i++) {
      for (j = 0; j < K[i % n]; j++) {
        if (S[i] == 'a')
          S[i] = 'Z';
        else if (S[i] == 'A')
          S[i] = 'z';
        else
          S[i] -= 1;
      }
    }
    printf("%s", S);
  }
  return 0;
}