#include <stdio.h>
#define MAX(x, y) (x) > (y) ? (x) : (y)

int main(void) {
  int n, tmp, max;
  char s[101];

  scanf("%d %s", &n, s);

  tmp = 0;
  max = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'I') {
      tmp++;
    } else {
      tmp++;
    }
    max = MAX(max, tmp);
  }
  printf("%d\n", max);

  return 0;
}
