#include <stdio.h>

int lday[26] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    dp[365], day[26][365] = {},
    dayc[26] =
        {}; //  day     コンテストが実施された日    dayc    dayのインデックス
int c[26], s[365][26];

int calc(int con, int dd) {
  int i, ans;
  ans = s[dd][con];

  for (i = 0; i < con; i++)
    ans -= c[i] * (dd - lday[i]);
  for (i = con + 1; i < 26; i++)
    ans -= c[i] * (dd - lday[i]);
  return (ans);
}

int main(void) {
  int d, D, ans[366], score = 0, tmpscore;
  int i, ii, iii, iv, tmp, tmp2;
  scanf("%d", &D);
  for (i = 0; i < 26; i++)
    scanf("%d", c + i);
  for (ii = 0; ii < D; ii++)
    for (i = 0; i < 26; i++)
      scanf("%d", &s[ii][i]);

  tmpscore = 0;
  for (d = 0; d < D; d++) {
    tmp = -1000000;
    for (i = 0; i < 26; i++) {
      tmp2 = calc(i, d);
      if (tmp2 > tmp) {
        tmp = tmp2;
        ans[d] = i;
      }
    }
    tmpscore += tmp;
    day[ans[d]][dayc[ans[d]]++] = d;
    lday[ans[d]] = d;
  }

  for (i = 0; i < D; i++)
    printf("%d\n", ans[i] + 1);
}