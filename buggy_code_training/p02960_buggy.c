
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char s[3000];
  scanf("%s", s);
  int n;
  n = strlen(s);

  int i, j, k, plus, z, last;
  long long ans[2][13];
  int amari[100000];
  int now = 1;
  for (i = 0; i < 100000; i++) {
    amari[i] = now;
    now = (now * 10) % 13;
  }

  char ch;
  ans[0][0] = 1;

  for (i = 0; i < n; i++) {
    ch = s[n - 1 - i];
    for (j = 0; j < 13; j++) {
      ans[(i + 1) % 2][j] = 0;
    }
    if (ch == '?') {
      for (k = 0; k < 10; k++) {
        plus = (amari[i] * k) % 13;
        for (j = 0; j < 13; j++) {
          ans[(i + 1) % 2][(j + plus) % 13] += ans[i % 2][j];
        }
      }
      for (j = 0; j < 13; j++) {
        ans[(i + 1) % 2][(j + plus) % 13] %= 1000000007;
      }
    } else {
      z = (int)ch - (int)'0';
      plus = (amari[i] * z) % 13;
      for (j = 0; j < 13; j++) {
        ans[(i + 1) % 2][(j + plus) % 13] = ans[i % 2][j];
      }
    }
    last = (i + 1) % 2;
  }

  printf("a:%lld", ans[last][5]);
}
