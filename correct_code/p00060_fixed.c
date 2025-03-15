#include <stdio.h>

int main(void) {
  int a, b, c;
  int i, count = 0;
  int p[11];
  while (scanf("%d %d %d", &a, &b, &c) != EOF) {
    for (i = 1; i < 11; i++) {
      p[i] = i;
      if (p[i] == a || p[i] == b || p[i] == c) {
        p[i] = 0;
      }
      if (a + b + p[i] > 20) {
        count = count + 1;
      }
    }
    if (count < 4) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
    count = 0;
  }
  return 0;
}