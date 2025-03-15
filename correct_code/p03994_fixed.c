#include <stdio.h>

int main() {

  char s[100001];
  int k;

  scanf("%s", s);
  scanf("%d", &k);

  int i = 0;
  char *c;

  for (c = s; *c != '\0'; c++) {
    if (*c == 'a')
      continue;
    int diff = ('z' + 1 - *c);
    if (k >= diff) {
      *c = 'a';
      k -= diff;
    }
  }
  c--;

  (*c) += (k % 26);

  printf("%s", s);

  return 0;
}
