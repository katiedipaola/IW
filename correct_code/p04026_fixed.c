
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  //変数の宣言

  char s[100010];
  int i, j, k;
  int len;
  int alphabet[30];
  int abets[30];
  int flag = 0;

  //データの読み込み
  scanf("%s", &s);

  //	printf("nは%dです\n", n);
  //	printf("データの読み込み終了\n");
  //実際の処理
  len = strlen(s);
  for (i = 0; i < len; i++) {
    for (j = 0; j < 26; j++) {
      if (s[i] == 'a' + j) {
        if (abets[j] == 0) {
          alphabet[j] = 1;
          abets[j] = i + 1;
        } else {
          flag = j + 1;
          break;
        }
      } else if (alphabet[j] == 1) {
        alphabet[j] = 0;
      } else {
        abets[j] = 0;
      }
      //			printf("%c
      //alphabet=%d,abets=%d\n",'a'+j,alphabet[j],abets[j]);
    }
    if (flag != 0) {
      printf("%d %d", abets[j], i + 1);
      return 0;
    }
  }

  //	printf("計算部分終了\n");

  //出力

  printf("-1 -1");

  //	printf("結果の出力終了\n");

  return 0;
}