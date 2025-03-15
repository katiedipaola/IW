/*
  B - Between a and b ...
  <http://abc048.contest.atcoder.jp/tasks/abc048_b>
  [Tips]
  ・変数の範囲に注意<http://seclan.dll.jp/c99d/c99d05.htm>
*/

#include <stdio.h>

typedef long long int int64_t;

int main(int argc, char const *argv[]) {

  int64_t a, b, x;

  if (scanf("%lld %lld %lld", &a, &b, &x) != EOF) {
    fprintf(stderr, "scanf ERROR!\n");
  }

  printf("%lld\n", (b / x) - (a != 0 ? a / x : 0));

  return 0;
}
