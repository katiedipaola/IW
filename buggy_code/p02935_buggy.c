#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
//　30min
int main(void) {
  int n;
  int v[1001];
  double ans;
  int tmp;

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }

  //    数値を降順にソート
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (v[i] > v[j]) {
        tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
      }
    }
  }

  ans = (((double)v[1]) + ((double)v[2])) / 2;
  //  ans = ans + (v[1] + v[2]) % 2;
  for (int i = 2; i < n; i++) {
    ans = (ans + ((double)v[i + 1])) / 2;
    //    ans += fmod(ans, v[i + 1]);
  }

  printf("%fd\n", ans);

  return 0;
}
