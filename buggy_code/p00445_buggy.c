#include <stdio.h>
int main() {
  char a[1001];
  int i = 0;
  int b;
  int c = 0, c1 = 0;
  while (scanf("%s", &a) != EOF) {
    c = 0;
    c1 = 0;
    i = 0;
    while (a[i + 2] != EOF) {
      if (a[i] == 'J' && a[i + 1] == 'O' && a[i + 2] == 'I') {
        c++;
      }
      if (a[i] == 'I' && a[i + 1] == 'O' && a[i + 2] == 'I') {
        c1++;
      }
      i++;
    }
    for (b = 0; b < 10000; b++) {
      a[b] = 0;
    }
    printf("%d\n%d\n", c, c1);
  }
  return 0;
}