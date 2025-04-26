// AOJ 2241: Usaneko Matrix
// 2017.12.9

#include <stdio.h>
#include <string.h>

#define N1 9 // 512
#define N2 511
int us[1000002], rus[502], cus[502], dus[2];
int ne[1000002], rne[502], cne[502], dne[2];
char buf[4005], *p;

int getint() {
  int n = 0;
  while (*p >= '0')
    n = (n << 3) + (n << 1) + (*p++ & 0xf);
  p++;
  return n;
}

int main() {
  int n, u, v, m, r, c, a, uu, vv, b;

  fgets(p = buf, 40, stdin);
  n = getint(), u = getint(), v = getint(), m = getint();
  for (r = 1; r <= n; r++) {
    fgets(p = buf, 4005, stdin);
    for (c = 1; c <= n; c++)
      us[getint()] = (r << 9) | c;
  }
  for (r = 1; r <= n; r++) {
    fgets(p = buf, 4005, stdin);
    for (c = 1; c <= n; c++)
      ne[getint()] = (r << 9) | c;
  }

  uu = vv = 0;
  while (m--) {
    fgets(p = buf, 40, stdin);
    a = getint();
    if (b = us[a]) {
      r = b >> N1, c = b & N2;
      if (++rus[r] == n)
        uu++;
      if (++cus[c] == n)
        uu++;
      if (r == c) {
        if (++dus[0] == n)
          uu++;
      }
      if (r + c == n + 1) {
        if (++dus[1] == n)
          uu++;
      }
    }
    if (b = ne[a]) {
      r = b >> N1, c = b & N2;
      if (++rne[r] == n)
        vv++;
      if (++cne[c] == n)
        vv++;
      if (r == c) {
        if (++dne[0] == n)
          vv++;
      }
      if (r + c == n + 1) {
        if (++dne[1] == n)
          vv++;
      }
    }
    if (n == 1) {
      if (uu > 1)
        uu = 1;
      if (vv > 1)
        vv = 1;
    }
    if (uu >= u && vv >= v) {
      puts("DRAW");
      return 0;
    } else if (uu >= u) {
      puts("USAGE");
      return 0;
    } else if (vv >= v) {
      puts("NEKO");
      return 0;
    }
  }
  puts("DRAW");
  return 0;
}