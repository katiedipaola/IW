#include <stdio.h>
#include <string.h>
#define W 21
#define H 21
int w, h;
char map[W][H];
int search(int s, int t) {
  if (s < 0 || t < 0 || s >= h || t >= w || map[s][t] == '#')
    return 0;
  int sum = 1;
  map[s][t] = '#';
  sum += search(s - 1, t);
  sum += search(s, t + 1);
  sum += search(s + 1, t);
  sum += search(s, t - 1);
  return sum;
}
int main() {
  int i, j;
  while (1) {
    int st_w, st_h;
    scanf("%d %d\n", &w, &h);
    if (!w && !h)
      break;
    memset(map, ' ', sizeof(map));
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        scanf("%c", &map[i][j]);
        if (map[i][j] == '@') {
          st_w = j;
          st_h = i;
        }
      }
      scanf("\n");
    }
    printf("%d\n", search(st_h, st_w));
  }
  return 0;
}