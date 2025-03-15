#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  int n;
  int ans = 0;
  int same = 0;
  long int x[51], y[51];
  int p, q;

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%ld%ld", &x[i], &y[i]);
  }

  ans = n;
  if (n > 1) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        // p,qの全パターンを出す
        // （p, qの値が同じパターンもあるかもだが気にしない）
        if (i != j) {
          p = x[i] - x[j];
          q = y[i] - y[j];
        }
        same = 0;
        for (int k = 1; k <= n; k++) {
          for (int l = 1; l <= n; l++) {
            // p, qで取れるものがあるか確認
            if (k != l) {
              if (p == (x[k] - x[l]) && q == (y[k] - y[l])) {
                same++;
              }
            }
          }
        }
        if (ans > (n - same)) {
          ans = (n - same);
        }
      }
    }
  }
  /*
 // 数値を降順にソート
  for (int i=0; i< n*2-1; i++) {
    for (int j=i+1; j<n*2; j++) {
      if (L[i] > L[j]) {
        tmp =  L[i];
        L[i] = L[j];
        L[j] = tmp;
      }
    }
  }
*/

  printf("%d\n", ans);

  return 0;
}
