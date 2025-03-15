#include <stdio.h>

int main(void) {
  char S[3];
  int count = 0;
  scanf("%s", S);
  for (int i = 0; i < 3; i++) {
    if (i == 0 && S[i] == 'R') {
      count += 1;
    } else {
      if (S[i] == 'R' && S[i - 1] == 'R') {
        count += 1;
      } else if (S[i] == 'R' && count == 0) {
        count += 1;
      } else {
        continue;
      }
    }
  }
  printf("%i", count);
  return 0;
}