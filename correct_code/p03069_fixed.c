#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void) {
  int n, w = 0, b = 0;
  scanf("%d", &n);
  char s[n + 1];
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      w++;
    }
  }
  if (w == 0 || w == n) {
    printf("0");
    return 0;
  }
  int ans = w;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      w--;
    } else {
      b++;
    }
    if (ans > w + b) {
      ans = w + b;
    }
  }
  printf("%d", ans);
  return 0;
}