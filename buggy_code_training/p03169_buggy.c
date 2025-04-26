#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double dp[303][303][303] = {0.0};

double f(int i, int j, int k, int n) {
  double tmp = 0.0;
  if (i == 0 && j == 0 && k == 0)
    return 0.0;
  if (dp[i][j][k] != 0.0)
    return dp[i][j][k];
  if (i > 0)
    tmp += f(i - 1, j, k, n) * i / (i + j + k);
  if (j > 0)
    tmp += f(i + 1, j - 1, k, n) * j / (i + j + k);
  if (k > 0)
    tmp += f(i, j + 1, k - 1, n) * k / (i + j + k);
  tmp += (double)n / (i + j + k);
  dp[i][j][k] = tmp;
  return tmp;
}

int main(void) {
  int n, a[304];
  double res;
  int cnt[3] = {0}; // 1個の個数,二個の個数,三個の個数
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    cnt[a[i] - 1]++;

  res = f(cnt[0], cnt[1], cnt[2], n);
  printf("%lf¥n", res);
  return 0;
}

/*
import numpy as np
n=int(input())
a = list(map(int,input().split()))
cnt = [0,0,0] #1個の個数、二個の個数、三個の個数
for i in range(n):
    cnt[a[i]-1] += 1

def f(i,j,k):
    if [i,j,k] == [0,0,0]:
        return 0.0
    if dp[i][j][k] != 0.0:
        return dp[i][j][k]
    tmp = 0.0
    if i>0:
        tmp += f(i-1,j,k)*float(i)/float(i+j+k)
    if j>0:
        tmp += f(i+1,j-1,k)*float(j)/float(i+j+k)
    if k>0:
        tmp += f(i,j+1,k-1)*float(k)/float(i+j+k)
    tmp += float(n)/float(i+j+k)


    dp[i][j][k] = tmp
    return tmp
dp = np.zeros((n+1,n+1,n+1))
#dp = [[[0.0 for i in range(n+1)] for j in range(n+1)] for k in range(n+1)]

print(f(cnt[0],cnt[1],cnt[2]))
*/