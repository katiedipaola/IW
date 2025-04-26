#include <stdio.h>

int main(void) {
  int money = 100000;
  int i, n;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    money += (money * 0.05);
  }

  if (money % 1000 != 0) {
    money = (money + 10000) / 10000 * 10000;
  }

  printf("%d\n", money);

  return (0);
}