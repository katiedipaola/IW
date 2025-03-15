#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int h, w, count[26] = {};
  scanf("%d%d", &h, &w);
  char a[h][w + 1], lowcmp[27] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < h; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = 0; k < 26; k++) {
        if (a[i][j] == lowcmp[k]) {
          count[k]++;
        }
      }
    }
  }
  int sum = 0;
  if (h % 2 == 0 && w % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (count[i] % 4 != 0) {
        printf("No\n");
        return 0;
      }
    }

  } else if (w % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (count[i] % 2 != 0) {
        printf("No\n");
        return 0;
      }
      sum += count[i] % 4;
      if (sum > w) {
        printf("No\n");
        return 0;
      }
    }
  } else if (h % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (count[i] % 2 != 0) {
        printf("No\n");
        return 0;
      }
      sum += count[i] % 4;
      if (sum > h) {
        printf("No\n");
        return 0;
      }
    }
  } else {
    bool odd = false;
    for (int i = 0; i < h; i++) {
      if (count[i] % 2 != 0) {
        if (odd == true) {
          printf("No\n");
          return 0;
        }
        odd = true;
      }
      sum += count[i] % 4;
      if (sum > h + w - 1) {
        printf("No\n");
        return 0;
      }
    }
  }
  printf("Yes\n");
  return 0;
}