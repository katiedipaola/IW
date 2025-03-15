#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b)) /* ２個の値の最大値 */
#define min(a, b) (((a) < (b)) ? (a) : (b)) /* ２個の値の最小値 */
#define ENTER printf("\n")                  /* 改行プリント */
int DBG = 0; /* デバッグプリント 提出時は0 */
/* main *************************************************************/
char s[100000];
int ans[100000] = {0};
int k[100000];
int main() {
  int a, b, c, i, j, n, m, x, y, r, l;

  scanf("%s", s);
  n = strlen(s);

  a = 'R';
  b = 0;
  for (i = 1; i < n - 1; i++) {
    if (s[i] != a) {
      if (a == 'R') {
        for (j = i - 1; j >= b; j--) {
          k[j] = i - j;
        }
        a = 'L';
        b = i;
      } else {
        for (j = b; j <= i - 1; j++) {
          k[j] = j - b + 1;
        }
        a = 'R';
        b = i - 1;
      }
    }
  }
  for (j = b; j <= n - 1; j++) {
    k[j] = j - b + 1;
  }
  if (DBG)
    for (i = 0; i < n; i++) {
      printf("%d ", k[i]);
    }
  if (DBG)
    ENTER;

  for (i = 0; i < n; i++) {
    if (s[i] == 'R') {
      if (k[i] % 2 == 0)
        ans[i + k[i]]++;
      else
        ans[i + k[i] - 1]++;
    } else {
      if (k[i] % 2 == 0)
        ans[i - k[i]]++;
      else
        ans[i - k[i] + 1]++;
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d", ans[i]);
    if (i != n - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }

  return 0;
}
