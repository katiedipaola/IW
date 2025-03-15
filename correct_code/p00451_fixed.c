#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define mem(x, y) (x *)malloc(sizeof(x) * (y))

int maximum(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

int minimum(int x, int y) {
  if (x < y)
    return x;
  else
    return y;
}

int main() {
  int len[2];
  char **str = mem(char *, 2);
  int max;
  int i, j;
  str[0] = mem(char, 4001);
  str[1] = mem(char, 4001);
  while (scanf("%s", str[0]) != EOF) {
    max = 0;
    scanf("%s", str[1]);
    len[0] = strlen(str[0]);
    len[1] = strlen(str[1]);
    if (len[0] > len[1])
      ;
    {
      char *tmp = str[0];
      str[0] = str[1];
      str[1] = tmp;
      len[0] ^= len[1];
      len[1] ^= len[0];
      len[0] ^= len[1];
    }
    int match = 0;
    for (i = -len[0] + 1; i < len[1]; i++) {
      for (j = maximum(0, i); j < minimum(len[1], i + len[0]); j += 1) {
        if (str[0][j - i] == str[1][j]) {
          match++;
          if (match > max) {
            max = match;
          }
        } else {
          match = 0;
        }
      }
      match = 0;
    }
    printf("%d\n", max);
  }
  return 0;
}