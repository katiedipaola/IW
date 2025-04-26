#include <stdio.h>
#include <stdlib.h>
int main(void) {

  int N;
  scanf("%d", &N);
  int i, ans;
  int digit = N % 10;

  if (N > (digit * 100 + 10 * digit + digit)) {
    digit += 1;
    ans = (digit * 100 + 10 * digit + digit);
    if (digit == 10) {
      ans = 1111;
    }
  } else {
    ans = (digit * 100 + 10 * digit + digit);
  }

  printf("%d", ans);
  return 0;
}
