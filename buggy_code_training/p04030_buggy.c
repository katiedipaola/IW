#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int i, j;
  char K[20], S[20];
  scanf("%s", &S);

  j = 0;
  for (i = 0; i < 20; i++)
    K[i] = '\0';
  for (i = 0; i < strlen(S); i++) {
    if (S[i] == '0')
      K[j++] = '0';
    else if (S[i] == '1')
      K[j++] = '1';
    else if (S[i] == 'B') {
      if (K[0] == '\0')
        continue;
      else
        K[j--] = '\0';
    }
    if (j < 0)
      j = 0;
  }
  printf("%s\n", K);
  return 0;
}
