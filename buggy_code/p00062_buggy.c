#include <stdio.h>
int main(void) {
  char a[10];
  while (scanf("%s", &a) != EOF) {
    int b[10], i, j;
    for (i = 0; i < 10; i++)
      b[i] = a[i] - '0';
    for (i = 8; i > 0; i--) {
      for (j = 0; j <= i; j++) {
        b[j] = (b[j] + b[j + 1]) % 10;
      }
    }
    printf("%d\n", b[0]);
  }
  return 0;
}