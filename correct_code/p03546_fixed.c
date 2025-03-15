#include <stdio.h>
int main() {
  int i, j, h, w, a, s = 0, mi, d[10][10], c[20], u[20] = {};
  scanf("%d %d", &h, &w);
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++)
      scanf("%d", &d[i][j]);
    c[i] = 1e9;
  }
  c[mi = 1] = 0;
  for (i = 0; i < 10; i++) {
    u[mi] = 1;
    for (j = 0; j < 10; j++) {
      if (c[j] > c[mi] + d[j][mi])
        c[j] = c[mi] + d[j][mi];
    }
    mi = 1;
    for (j = 0; j < 10; j++) { // printf("%d ",c[j]);
      if (u[j])
        continue;
      if (mi == 1 || c[mi] > c[j])
        mi = j;
    } // printf("\n");
  }
  // for(i=0;i<10;i++)printf("%d\n",c[i]);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      scanf("%d", &a);
      if (a >= 0)
        s += c[a];
    }
  }
  printf("%d\n", s);
  return 0;
}
