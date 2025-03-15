#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
  long long n;
  long long grp[200000] = {0};
  int huka = 0;
  scanf("%lld", &n);
  //もし、nが奇数→0 202 42024 6420246
  //もし、nが偶数→11 3113 531135   でなければならない
  long long data[n];
  int loop1;
  for (loop1 = 0; loop1 < n; loop1++) {
    scanf("%lld", &data[loop1]);
    grp[data[loop1]]++;
  }
  //不可能かチェック
  for (loop1 = 0; loop1 < n; loop1++) {
    if (n % 2 == 0) {
      if (loop1 % 2 == 0 && grp[loop1] != 0) {
        huka = -1;
      }
      if (loop1 % 2 == 1 && grp[loop1] != 2) {
        huka = -1;
      }
    }
    if (n % 2 == 1) {
      if (loop1 == 0) {
        if (grp[loop1] != 1) {
          huka = -1;
        }
      } else if (loop1 % 2 == 1 && grp[loop1] != 0) {
        huka = -1;
      } else if (loop1 % 2 == 0 && grp[loop1] != 2) {
        huka = -1;
      }
    }
  }
  if (huka == -1) {
    printf("0\n");
    return 0;
  }
  //パターン数はいくつか
  long long teisu = pow(10, 9) + 7;
  long long patt = 1;
  for (loop1 = 0; loop1 < (n / 2); loop1++) {
    patt *= 2;
    patt %= teisu;
    // printf("%lld\n",patt);
  }
  printf("%lld\n", patt);
  return 0;
}