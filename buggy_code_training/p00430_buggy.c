/*
  AOJ 0507
  Title:Square
  @kankichi573
*/
#include <stdio.h>
#define min(x, y) (((x) < (y)) ? (x) : (y))

int prefix[31];

void print_prefix(int len) {
  int i;

  for (i = 0; i < len; i++)
    printf("%d ", prefix[i]);
}
void print_square(int sum, int len, int max_) {
  int i;

  // printf(":%d %d %d\n",sum,len,max_);

  if (sum <= 0)
    return;

  if (sum <= max_) {
    print_prefix(len);
    printf("%d\n", sum);
  } else if (1 == max_ || 1 == sum) {
    print_prefix(len);
    for (i = 0; i < sum; i++) {
      printf("1");
      if (i < sum - 1)
        printf(" ");
    }
    printf("\n");
  }

  if (max_ > 1)
    for (i = min(max_ - 1, sum - 1); i >= 1; i--) {
      prefix[len] = i;
      print_square(sum - i, len + 1, i);
    }
}

main() {
  int i, ret, N;

  while (scanf("%d", &N) && (N))
    print_square(N, 0, N);
  return (0);
}