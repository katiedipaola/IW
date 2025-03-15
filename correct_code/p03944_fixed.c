#include <stdio.h>

int main(void) {
  int w, h, n;
  scanf("%d %d %d", &w, &h, &n);
  char ans[w + 1][h + 1];
  int i, j;
  for (i = 0; i <= w - 1; i++) {
    for (j = 0; j <= h - 1; j++) {
      ans[i][j] = 0;
    }
  }

  int i1;
  for (i1 = 1; i1 <= n; i1++) {
    int a1, a2, a3;
    scanf("%d %d %d", &a1, &a2, &a3);

    int c, d;
    switch (a3) {
    case 1:
      for (c = 0; c < a1; c++) {
        for (d = 0; d <= h - 1; d++) {
          ans[c][d] = 1;
        }
      }
      break;
    case 2:
      for (c = a1; c <= w - 1; c++) {
        for (d = 0; d <= h - 1; d++) {
          ans[c][d] = 1;
        }
      }
      break;
    case 3:
      for (c = 0; c <= w - 1; c++) {
        for (d = 0; d < a2; d++) {
          ans[c][d] = 1;
        }
      }
      break;
    case 4:
      for (c = 0; c <= w - 1; c++) {
        for (d = a2; d <= h - 1; d++) {
          ans[c][d] = 1;
        }
      }
      break;
    }
  }
  int white = 0;
  int s1, s2;
  for (s1 = 0; s1 <= w - 1; s1++) {
    for (s2 = 0; s2 <= h - 1; s2++) {
      if (ans[s1][s2] == 0) {
        white++;
      }
    }
  }
  printf("%d", white);
  return 0;
}
