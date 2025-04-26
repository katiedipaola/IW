#include <stdio.h>
#define gc getchar_unlocked
#define pc putchar_unlocked

int ini() {
  int v = 0;
  for (char c = gc(); '0' <= c && c <= '9'; c = gc())
    v = v * 10 + (c - '0');
  return v;
}

void puti(int v) {
  char b[10];
  int n = 0;
  while (v)
    b[n++] = '0' + v % 10, v /= 10;
  if (!n)
    b[n++] = '0';
  while (n--)
    pc(b[n]);
}

int Gcd(int n, int m) { return m ? Gcd(m, n % m) : n; }

int main() {
  int x = ini();
  puti(x / Gcd(360, x));
}