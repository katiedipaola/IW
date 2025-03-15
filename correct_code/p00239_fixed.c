#include <stdio.h>
typedef struct {
  int no;
  int b, c, d;
  int cal;
} P;
int main() {
  int n, i, flg;
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    P tmp[n];
    P max;
    for (i = 0; i < n; i++) {
      scanf("%d %d %d %d", &tmp[i].no, &tmp[i].b, &tmp[i].c, &tmp[i].d);
      tmp[i].cal = (tmp[i].b + tmp[i].d) * 4 + tmp[i].c * 9;
    }
    scanf("%d %d %d %d", &max.b, &max.c, &max.d, &max.cal);

    for (i = 0, flg = 0; i < n; i++) {
      if (max.b >= tmp[i].b && max.c >= tmp[i].c && max.d >= tmp[i].d &&
          max.cal >= tmp[i].cal) {
        printf("%d\n", tmp[i].no);
        flg = 1;
      }
    }
    if (flg == 0)
      printf("NA\n");
  }
  return 0;
}