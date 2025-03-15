#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define P 1000000007

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int compw(const void *a, const void *b) {
  return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}
int compr(const void *a, const void *b) { return *(int *)b - *(int *)a; }

uint32_t nextpint(void) {
  char c = getchar();
  while (c < '0' || '9' < c)
    c = getchar();
  uint_fast32_t x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
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

inline int min2(const int a, const int b) { return a > b ? b : a; }
inline int dif2(const int a, const int b) { return a > b ? a - b : b - a; }

char s[100002];
char t[100001];
int d[100002][26];
int main(void) {
  int n = nextstr(s + 1);
  int m = nextstr(t);
  for (int i = n; i > 0; i--) {
    for (int c = 0; c < 26; c++) {
      d[i][c] = d[i + 1][c];
    }
    int c = s[i] - 'a';
    d[i][c] = i;
  }
  for (int c = 0; c < 26; c++) {
    d[0][c] = d[1][c];
  }
  int ans = 0;
  int now = 0;
  for (int i = 0; i < m; i++) {
    int c = t[i] - 'a';
    now++;
    if (d[now][c] != 0) {
      now = d[now][c];
    } else if (d[0][c] != 0) {
      now = d[0][c];
      ans++;
    } else {
      puts("-1");
      return 0;
    }
  }
  printf("%ld\n", (long)ans * n + now);
}
