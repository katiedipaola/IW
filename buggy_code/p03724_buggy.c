#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define llong long long
#define fr(i, l, r) for (i = (l); i < (r); i++)
#define min(p, q) ((p) < (q) ? (p) : (q))
#define max(p, q) ((p) > (q) ? (p) : (q))

int main(void) {
  //変数の宣言
  int n, m;
  int a, b;
  int num[100010];

  //よく使う変数
  int i, j, k, l;
  int flag = 0;
  int ans = 0;
  int count = 0;
  long long int temp, temp1, temp2;
  int max, min;
  int len;
  //データの読み込み

  scanf("%d %d", &n, &m);

  for (i = 0; i < 100010; i++) {
    num[i] = 0;
  }

  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    num[a]++;
    num[b]++;
  }

  //	printf("nは%dです\n", n);
  //	printf("データの読み込み終了\n");
  //実際の処理

  for (i = 1; i <= n; i++) {
    if (num[i] % 2 == 1)
      flag = 1;
  }

  //	printf("計算部分終了\n");
  //出力

  if (flag == 0) {
    printf("YES");
  } else {
    printf("NO");
  }

  //	printf("結果の出力終了\n");

  return 0;
}
