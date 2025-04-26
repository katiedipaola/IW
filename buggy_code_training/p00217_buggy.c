#include <stdio.h>
typedef struct {
  int nam;
  int dis;
} set;
int main() {
  int n, i, way1, way2, top = 0, rancer;
  while (scanf("%d", &n)) {
    if (n == 0) {
      break;
    }

    set mem[10000];
    for (i = 0; i < n; i++) {
      mem[i].dis = 0;
    }

    for (i = 0; i < n; i++) {
      scanf("%d %d %d", &mem[i].nam, &way1, &way2);
      mem[i].dis += way1 + way2;
    }

    for (i = 0; i < n; i++) {
      if (mem[i].dis > top) {
        top = mem[i].dis;
        rancer = mem[i].nam;
      }
    }

    printf("%d %d", rancer, top);
    top = 0;
  }
  return 0;
}