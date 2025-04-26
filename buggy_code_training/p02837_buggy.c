#include <stdio.h>
int main(void) {
  int N;
  scanf("%d", &N);
  int A[N + 1], x[N + 1][211][2], y[N + 1][211][2], mujunn = 0, flag = 0,
                                                    max = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    for (int j = 0; j < A[i]; j++) {
      scanf("%d %d", &x[i][j][0], &y[i][j][0]);
    }
  }
  int honest[N + 1], c;
  for (int i = 0; i < (1 << N); i++) { /// 333
    c = 0;
    mujunn = 0;
    // printf("%dパターン目",i+1);
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        honest[c] = j + 1;
        c++;
        //   printf("%dさん\t",j+1);
      }
    }
    // printf("合計%d人\n",c);
    for (int l = 0; l < c; l++) { //正直者候補のうち誰に注目するか222
      if (mujunn == 1) {
        break;
      }
      for (int j = 0; j < A[honest[l] - 1]; j++) { //証言を一つ一つ注目111
        if (mujunn == 1)
          break;
        for (int k = 0; k < c; k++) {
          if (x[honest[l] - 1][j][0] ==
              honest[k] - 1) { //証言された人が正直者か否か
                               // for回し終えた時点でflag=0なら正直者
            flag = 1;
          }
        }

        if (!flag) {
          if (y[honest[l] - 1][j][0] == 1) {
            mujunn = 1;
            //     printf("%dさんはピエロだが、%d(正直)と証言しているので矛盾\n",x[honest[l]-1][j][0],
            //          y[honest[l]-1][j][0]);
          }
        } else {
          if (y[honest[l] - 1][j][0] == 0) {
            mujunn = 1;
            //   printf("%dさんは正直者だが、%d(ピエロ)と証言しているので矛盾\n",x[honest[l]-1][j][0],
            //              y[honest[l]-1][j][0]);
          }
        }
        flag = 0;
      }                //証言1つに関するfor文閉じ111
    }                  // 222
    if (mujunn == 0) { //矛盾テストクリアの時
      if (c > max)
        max = c;
      //  printf("更新\n");
    }

  } /// 333
  printf("%d", max);

  return 0;
}
