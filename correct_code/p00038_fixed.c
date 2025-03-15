#include <stdio.h>

int main() {
  int card[14];
  int c[5];
  int i, j, t;
  int pair, tri, fo, st;
  int flag = 0;
  while (scanf("%d,%d,%d,%d,%d", &c[0], &c[1], &c[2], &c[3], &c[4]) != EOF) {
    flag = pair = tri = fo = st = 0;
    for (i = 1; i < 14; i++)
      card[i] = 0;
    for (i = 0; i < 5; i++) {
      card[c[i]]++;
      if (card[c[i]] == 4) {
        printf("four card\n");
        flag = 1;
        break;
      } else if (card[c[i]] == 3)
        tri = 1;
    }
    if (flag)
      continue;
    if (tri) {
      for (i = 1; i < 14; i++) {
        if (card[i] == 2)
          break;
      }
      if (card[i] == 2)
        printf("full house\n");
      else
        printf("three card\n");
      continue;
    }
    for (i = 1; i < 14; i++) {
      if (card[i] == 2)
        pair++;
    }
    if (pair == 2) {
      printf("two pair\n");
      continue;
    } else if (pair == 1) {
      printf("one pair\n");
      continue;
    }
    for (i = 1; i < 10; i++) {
      if (card[i] == 1 && card[i + 1] == 1 && card[i + 2] == 1 &&
          card[i + 3] == 1 && card[i + 4] == 1) {
        printf("straight\n");
        st = 1;
        break;
      }
    }
    if (st)
      continue;
    if (card[1] == 1 && card[10] == 1 && card[11] == 1 && card[12] == 1 &&
        card[13] == 1) {
      printf("straight\n");
      st = 1;
    }

    else
      printf("null\n");
  }
  return 0;
}
