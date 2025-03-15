#include <stdio.h>
#include <string.h>

int main() {
  char s[50], t[50];
  int flug = 0, lens, lent;
  scanf("%s", s);
  scanf("%s", t);
  lens = strlen(s);
  lent = strlen(t);
  for (int i = lens - 1; i >= 0; i--) {
    for (int j = i; j >= 0 && i - j + 1 <= lent &&
                    (s[j] == '?' || s[j] == t[lent - i + j - 1]);
         j--) {
      if (i - j + 1 == lent && flug == 0)
        flug = 1;
    }
    if (flug == 1) {
      for (int j = lent - 1; j >= 0; j--, i--) {
        s[i] = t[j];
      }
      flug = 2;
    } else {
      if (s[i] == '?') {
        s[i] = 'a';
      }
    }
  }
  printf("%s\n", (flug == 0) ? "UNRESTORABLE" : s);
  return 0;
}
