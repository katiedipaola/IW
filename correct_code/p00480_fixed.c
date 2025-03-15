#include <stdio.h>

unsigned long long kazu[100][21];
unsigned long long kazoe(int *, int, int, int);

int main(int argc, char *argv[]) {
  /*declare values*/
  int suuzi[100];
  int kosuu;
  unsigned long long count;
  int i, j;
  /*do work*/
  scanf("%d", &kosuu);
  for (i = 0; i < kosuu; i++) {
    scanf("%d", &suuzi[i]);
    for (j = 0; j <= 20; j++)
      kazu[i][j] = -1;
  }
  count = kazoe(suuzi, 1, suuzi[0], kosuu);
  printf("%llu\n", count);
  return 0;
}

unsigned long long kazoe(int *suuzi, int now, int nowsum, int max) {
  unsigned long long sum = 0, result;
  int nowsuuzi;
  if (now == max - 1) {
    if (nowsum == suuzi[now])
      return 1;
    else
      return 0;
  }
  if (suuzi[now] != 0) {
    nowsuuzi = nowsum + suuzi[now];
    if (nowsuuzi >= 0 && nowsuuzi <= 20) {
      if (kazu[now][nowsuuzi] == -1) {
        result = kazoe(suuzi, now + 1, nowsuuzi, max);
        kazu[now][nowsuuzi] = result;
      }
      sum += kazu[now][nowsuuzi];
    }
    nowsuuzi = nowsum - suuzi[now];
    if (nowsuuzi >= 0 && nowsuuzi <= 20) {
      if (kazu[now][nowsuuzi] == -1) {
        result = kazoe(suuzi, now + 1, nowsuuzi, max);
        kazu[now][nowsuuzi] = result;
      }
      sum += kazu[now][nowsuuzi];
    }
  } else {
    if (kazu[now][nowsum] == -1) {
      result = kazoe(suuzi, now + 1, nowsum, max) * 2;
      kazu[now][nowsum] = result;
    }
    sum += kazu[now][nowsum];
  }
  return sum;
}