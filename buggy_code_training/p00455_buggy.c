#include <stdio.h>
int main(void) {
  int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, V, w, x, y,
      z, A, B, C, D, E, F, G, H, I, J;
  scanf("%d %d %d %d %d %d\n%d %d %d %d %d %d\n%d %d %d %d %d %d", &a, &b, &c,
        &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p, &q, &r);
  s = 3600 * a + 60 * b + c;
  t = 3600 * d + 60 * e + f;
  u = 3600 * g + 60 * h + i;
  V = 3600 * j + 60 * k + l;
  w = 3600 * m + 60 * n + o;
  x = 3600 * p + 60 * q + r;
  y = t - x;
  z = V - u;
  A = x - w;
  B = y / 3600;
  C = y / 60 - B * 60;
  D = y - B * 3600 - C * 60;
  E = z / 3600;
  F = z / 60 - E * 60;
  G = z - E * 3600 - F * 60;
  H = A / 3600;
  I = A / 60 - H * 60;
  J = A - H * 3600 - I * 60;
  printf("%d %d %d\n%d %d %d\n%d %d %d\n", B, C, D, E, F, G, H, I, J);
  return 0;
}