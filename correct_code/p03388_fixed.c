#include <float.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#ifdef __cplusplus
#include <bits/stdc++.h>
#endif

#define getchar getchar_unlocked
#define putchar putchar_unlocked
int32_t nextint(void) {
  char c = getchar();
  while (c != '-' && (c < '0' || '9' < c))
    c = getchar();
  bool s = false;
  if (c == '-') {
    s = true;
    c = getchar();
  }
  uint32_t x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return s ? -x : x;
}
int64_t nextlong(void) {
  char c = getchar();
  while (c != '-' && (c < '0' || '9' < c))
    c = getchar();
  int s = 0;
  if (c == '-') {
    s = 1;
    c = getchar();
  }
  uint64_t x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return s ? -x : x;
}
uint32_t nextstr(char *s) {
  char c = getchar();
  while (c == ' ' || c == '\n')
    c = getchar();
  uint32_t len = 0;
  while (c != ' ' && c != '\n') {
    *s++ = c;
    len++;
    c = getchar();
  }
  *s = '\0';
  return len;
}

int main(void) {
  int q = nextint();
  while (q-- > 0) {
    long a = nextint();
    long b = nextint();
    if (a > b) {
      int t = a;
      a = b;
      b = t;
    }
    long ans;
    if (a == b) {
      ans = a * 2 - 2;
    } else if (a + 1 == b) {
      ans = a * 2 - 2;
    } else {
      long c = floorl(sqrtl(a * b - 1));
      if (c * (c + 1) >= a * b) {
        ans = c * 2 - 2;
      } else {
        ans = c * 2 - 1;
      }
    }
    printf("%ld\n", ans);
  }
}
