#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b)) /* ２個の値の最大値 */
#define min(a, b) (((a) < (b)) ? (a) : (b)) /* ２個の値の最小値 */
#define ENTER printf("\n")                  /* 改行プリント */
int DBG = 1; /* デバッグプリント 提出時は0 */
/* main *************************************************************/
int a[100001], dp[100001], grp[100001] = {0};

int main() {
  int g, c, i, j, k, n, x, y, pre, ans;

  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  if (n > 1) {
    ans = 1;
    grp[ans] = a[1];
    for (i = 2; i <= n; i++) {
      if (grp[ans] >= a[i]) {
        grp[++ans] = a[i];
      } else {
        for (j = 1; j <= ans; j++) {
          if (grp[j] < a[i]) {
            grp[j] = a[i];
            break;
          }
        }
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
