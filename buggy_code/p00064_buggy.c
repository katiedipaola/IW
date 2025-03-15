#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void) {
  char str[81];
  int count = 0, length, i, j = 0, k = 0;

  while (scanf("%s", str) != EOF) {
    length = strlen(str);
    for (i = length - 1; i >= 0; i--) {
      if (isdigit(str[i])) {
        j = 0;
        while (1) {
          if (isdigit(str[i - j])) {
            count += (str[i - j] - '0') * (pow(10, j));
            k++;
          } else {
            i -= k;
            break;
          }
          j++;
        }
      }
    }
  }
  printf("%d\n", count);

  return 0;
}