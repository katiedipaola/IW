#include <stdio.h>
#include <string.h>

int main(void) {
  char s[200001];

  scanf("%s", s);

  long int k = 0, ans = 0;
  int i;

  for (i = 0; i < strlen(s); i++) {
    if (s[i] == 'A')
      k++;
    else if (s[i] == 'B' && s[i + 1] == 'C') {
      ans += k;
      i++;
    } else
      k = 0;
  }

  printf("%ld\n", ans);

  return 0;
}