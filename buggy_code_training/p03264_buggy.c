#include <stdio.h>

int main(int argc, char argv[]) {
  int K, ans;
  scanf("%d", K);

  if (K % 2 == 1) {
    ans = (K / 2) * (K / 2 + 1);
  } else {
    ans = (K / 2) * (K / 2);
  }

  printf("%d\n", ans);

  return 0;
}
