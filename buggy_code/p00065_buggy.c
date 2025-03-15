#include <stdio.h>
#define isNum(a) (a <= '9' && a >= '0')
#define N_MAX 500 // 適当

char ch;
int c[N_MAX], f[N_MAX];

int parseInt() {
  int res = ch - '0';
  while (ch = getchar(), isNum(ch))
    res = res * 10 + ch - '0';
  return res;
}

int main(void) {
  int n;

  for (n = 0; n < N_MAX; n++)
    c[n] = f[n] = 0;

  while (ch = getchar(), isNum(ch)) {
    n = parseInt();
    c[n]++, f[n] = -1;

    while (ch != '\n')
      ch = getchar();
  }

  while (ch = getchar(), isNum(ch)) {
    n = parseInt();
    c[n]++, f[n] = f[n] ? 1 : 0;

    while (ch != '\n')
      ch = getchar();
  }

  for (n = 0; n < N_MAX; n++)
    if (f[n] == 1)
      printf("%d %d\n", n, c[n]);

  return 0;
}