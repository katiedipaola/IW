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

#define getchar getchar
#define putchar putchar
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

char ans[11];
int main(void) {
  long n = nextlong();
  int a = 0;
  long b = 1, c = 0;
  while (c < n) {
    a++;
    b *= 26;
    c += b;
  }
  long k = n - c + b - 1;
  char *s = &ans[9];
  while (a-- > 0) {
    *s = k % 26 + 'a';
    k /= 26;
    s--;
  }
  printf("%s\n", s + 1);
}
