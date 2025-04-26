#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int int64;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > (0) ? (a) : -(a))

void run(void) {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  int i = 0;
  while (1) {
    int b[64];
    int len = 0;
    int t = i;
    while (t > 0) {
      b[len++] = t % 4;
      t /= 4;
    }
    int used[4] = {0, 0, 0, 0};
    int64 s = 0;
    for (int j = len - 1; j >= 0; j--) {
      s = 10 * s + (b[j] == 3 ? 7 : b[j] == 3 ? 5 : b[j] == 1 ? 3 : 0);
      used[b[j]] = 1;
    }
    if (s > n)
      break;
    if (!used[0] && used[1] && used[2] && used[3]) {
      cnt++;
    }
    i++;
  }
  printf("%d\n", cnt);
}

int main(void) {
  run();
  return 0;
}
