#include <stdio.h>

int cnt_koisi[50];

int cheak_isi(int nin, int hito) {
  int h;
  for (h = 0; h < nin; h++) {
    if (h != hito) {
      if (cnt_koisi[h] > 0)
        return 0;
    }
  }
  return 1;
}

int main(void) {
  int n, p, i;
  int turn = 0;
  while (1) {
    scanf("%d %d", &n, &p);
    if (n == 0 && p == 0)
      break;
    turn = 0;
    for (i = 0; i < n; i++) {
      cnt_koisi[i] = 0;
    }
    while (1) {
      if (p > 0) { //回ってきたとき
        p--;
        cnt_koisi[turn]++;
        if (p == 0) { //一つ取った時
          if (cheak_isi(n, turn)) {
            printf("%d", turn);
            break;
          }
        }

      } else { //お椀の中に入ってなかった時
        p = cnt_koisi[turn];
        cnt_koisi[turn] = 0;
      }
      turn++;
      if (turn > n - 1)
        turn = 0;
    }
  }
  return 0;
}