#include <stdio.h>

int main(void) {
  int i, t, n, s, f, total;
  /*
  1行目 １日の目標時間t（整数）
  2行目 勉強の回数 n（整数）
  3行目 第1の勉強の開始時刻s 終了時刻f（整数 整数；半角空白区切り）
  ：
  n+2行目 第nの勉強の開始時刻s 終了時刻f
  */

  while (scanf("%d\n", &t) == 1) {
    if (!t)
      break;
    total = 0;

    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
      scanf("%d %d\n", &s, &f);
      total = total + f - s;
    }

    t -= total;
    if (t > 0) {
      printf("%d\n", t);
    } else {
      printf("OK\n");
    }
  }

  return 0;
}