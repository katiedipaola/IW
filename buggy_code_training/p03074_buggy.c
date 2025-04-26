#include <stdio.h>
#include <string.h>

// 0:直立
// 1:逆立ち
//今回は連続で逆立ちさせたい
// num[]の偶数番が0の個数

int main(void) {

  char str[100002];
  int i, j;
  int n, k;
  int count_ichi;
  int count_zero;
  int count = 0;
  int num[300000] = {0};
  int max = 0;
  int sum = 0;

  scanf("%d%d%s", &n, &k, str);

  str[n] = '5';

  if (str[0] == '0') {
    count++;
    num[0] = 0;
  }

  for (i = 0; i < n; i++) {
    if (str[i] == '1') {
      count_ichi = 1;
      for (j = i + 1; j <= n; j++) {
        if (str[j] == '1') {
          count_ichi++;
        } else {
          num[count] = count_ichi;
          count++;
          break;
        }
      }
      i = j - 1;
    } else {
      count_zero = 1;
      for (j = i + 1; j <= n; j++) {
        if (str[j] == '0') {
          count_zero++;
        } else {
          num[count] = count_zero;
          count++;
          break;
        }
      }
      i = j - 1;
    }
  }

  for (i = 0; i < 2 * k + 1; i++) {
    sum += num[i];
  }

  for (i = 2 * k + 1; i < n; i = i + 2) {
    sum += (num[i] + num[i + 1]);
    sum -= (num[i - 2 * k - 1] + num[i - 2 * k]);

    if (max < sum) {
      max = sum;
    }
  }

  printf("%d\n", max);

  return 0;
}