#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 200004
typedef long long ll;

void main(void) {

  ll N = 0, ans = 0;
  // scanf("%d",&N);
  char str[n];
  scanf("%s", str);
  ll i = 0;
  while (str[i] != '\0') {
    i++;
    N++;
  }
  ll str_int[N + 1], tmp = 0, tmp1 = 1;
  // str_int[0]=atol(str);
  for (ll j = 1; j <= N; j++) {
    str_int[j] = str[j] - '0';
  }

  tmp = 0;
  ll mod[2019] = {0};
  ;
  for (ll k = 0; k <= (N - 1); k++) {
    tmp += tmp1 * str_int[N - k];
    tmp = tmp % 2019;
    tmp1 = (tmp1 * 10) % 2019;
    mod[tmp]++;
  }
  mod[0]++;
  for (ll k = 0; k <= 2018; k++) {
    ans += mod[k] * (mod[k] - 1) / 2;
  }

  printf("%lld", ans);
}