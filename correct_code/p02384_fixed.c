#include <stdio.h>

int main() {
  int i, j, k, n, a, b, Dice[7], side[5] = {2, 3, 5, 4, 2};
  char order[7][3] = {"", "", "N", "W", "E", "S", "NN"};

  //ダイスの目の入力
  for (i = 1; i < 7; i++) { // 1 ~ 6 Dice[]
    scanf("%d", &Dice[i]);
  }

  //質問の数の入力
  scanf("%d", &n);

  //上面を合わせる
  //側面の入力
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);

    for (j = 1; Dice[j] != a; j++) {
    } // 1 ~   aじゃない
    //回す
    for (k = 0; order[j][k] != '\0'; k++) {

      Dice[0] = Dice[1];

      switch (order[j][k]) {

      case 'E':
        Dice[1] = Dice[4];
        Dice[4] = Dice[6];
        Dice[6] = Dice[3];
        Dice[3] = Dice[0];
        break;

      case 'N':
        Dice[1] = Dice[2];
        Dice[2] = Dice[6];
        Dice[6] = Dice[5];
        Dice[5] = Dice[0];
        break;

      case 'S':
        Dice[1] = Dice[5];
        Dice[5] = Dice[6];
        Dice[6] = Dice[2];
        Dice[2] = Dice[0];
        break;

      case 'W':
        Dice[1] = Dice[3];
        Dice[3] = Dice[6];
        Dice[6] = Dice[4];
        Dice[4] = Dice[0];
        break;
      }
    }

    for (j = 0; b != Dice[side[j]]; j++)
      ;

    printf("%d\n", Dice[side[j + 1]]);
  }

  return 0;
}
