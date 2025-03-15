#include <stdio.h>
int main() {
  int i, j;
  char s[1010];
  char c[] = {"1234567890TLURD"};
  char w[] = {" kstnhmyrwaiueo"};
  scanf("%s", s);
  for (i = 0; s[i]; i++) {
    if (s[i] == '1')
      continue;
    if (s[i] == '0' && s[i + 1] == 'U') {
      printf("nn");
      continue;
    }
    for (j = 0; s[i] - c[j]; j++)
      ;
    printf("%c", w[j]);
  }
  printf("\n");
  return 0;
}