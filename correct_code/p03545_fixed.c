#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int N;
  int N0, N1, N2, N3;
  int f0 = 0, f1 = 0, f2 = 0;
  int ans[8];
  char op0, op1, op2;
  int flag;
  int i;
  // 整数の入力
  scanf("%d", &N);
  N0 = N % 10;
  N1 = (N / 10 % 10);
  N2 = (N / 100) % 10;
  N3 = N / 1000;

  ans[0] = N3 + N2 + N1 + N0;
  ans[1] = N3 + N2 + N1 - N0;
  ans[2] = N3 + N2 - N1 + N0;
  ans[3] = N3 - N2 + N1 + N0;
  ans[4] = N3 + N2 - N1 - N0;
  ans[5] = N3 - N2 - N1 + N0;
  ans[6] = N3 - N2 + N1 - N0;
  ans[7] = N3 - N2 - N1 - N0;

  for (i = 0; i < 7; i++) {
    if (7 == ans[i]) {
      flag = i;
      break;
    }
  }
  //        printf("%d\n",flag);
  switch (flag) {
  case 0:
    op0 = '+';
    op1 = '+';
    op2 = '+';
    break;
  case 1:
    op0 = '+';
    op1 = '+';
    op2 = '-';
    break;
  case 2:
    op0 = '+';
    op1 = '-';
    op2 = '+';
    break;
  case 3:
    op0 = '-';
    op1 = '+';
    op2 = '+';
    break;
  case 4:
    op0 = '+';
    op1 = '-';
    op2 = '-';
    break;
  case 5:
    op0 = '-';
    op1 = '-';
    op2 = '+';
    break;
  case 6:
    op0 = '-';
    op1 = '+';
    op2 = '-';
    break;
  case 7:
    op0 = '-';
    op1 = '-';
    op2 = '-';
    break;
  default:
    // printf("others\n");
    break;
  }

  printf("%d%c%d%c%d%c%d=7\n", N3, op0, N2, op1, N1, op2, N0);
  //   if ((f0&f1)||(f1&f2)){
  //     printf("Yes\n");
  //  }else {
  // printf("No\n");
  //}
  return 0;
}
