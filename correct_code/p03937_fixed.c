#include <stdio.h>

int main() {
  int h, w, i, j, cnt = 0;
  char a[9][9];

  scanf("%d %d", &h, &w);

  for (i = 0; i < h; i++) {
    scanf("%s", a[i]);
  }

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (a[i][j] == '#')
        cnt++;
    }
  }

  if (cnt == h + w - 1)
    printf("Possible");
  else
    printf("Impossible");
}