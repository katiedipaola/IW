#include <stdio.h>

int main() {
  char S[3][101], trn = 0, crd;
  int p[3] = {0, 0, 0};
  scanf("%s\n%s\n%s", S[0], S[1], S[2]);
  while (1) {
    crd = S[(int)trn][p[(int)trn]];
    if (crd == '\0') {
      printf("%c\n", 'a' + trn);
      break;
    } else {
      p[(int)trn]++;
      trn = crd - 'a';
    }
  }
  return 0;
}
