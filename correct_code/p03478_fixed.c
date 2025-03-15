#include <stdio.h>
int main(void) {
  int N, A, B, i, num1, dig, sum1 = 0, sum2;
  scanf("%d", &N);
  scanf("%d", &A);
  scanf("%d", &B);
  for (i = 1; i <= N; i++) {
    num1 = i;
    sum2 = 0;
    while (num1 != 0) {
      dig = num1 % 10;
      sum2 = sum2 + dig;
      num1 = num1 / 10;
    }
    if ((A <= sum2) && (sum2 <= B))
      sum1 += i;
  }
  printf("%d", sum1);
  return 0;
}