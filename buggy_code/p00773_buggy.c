#include <stdio.h>

int shouhi(int n, int m) { return n * (100 + m) / 100; }

int main() {
  int X, Y, s, a, b, i, A = 0, B = 0;
  for (i = 0; i < 1000; i++) {
    scanf("%d %d %d", &X, &Y, &s);
    A = 0;
    B = 0;
    if ((X == 0) && (Y == 0) && (s == 0)) {
      return 0;
    }
    for (a = 1; a < 1000; a++) {
      for (b = a + 1; b < 1000; b++) {
        if ((shouhi(a, X) + shouhi(b, X) == s) &&
            (shouhi(a, Y) + shouhi(b, Y) >= shouhi(A, Y) + shouhi(B, Y))) {
          A = a;
          B = b;
        }
      }
    }
    printf("%d\n", shouhi(A, Y) + shouhi(B, Y));
  }

  return 0;
}