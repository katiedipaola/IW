#include <stdio.h>
int main() {
  int i, j, n, count = 0, number = 0;
  scanf("%d", &n);
  for (j = 1; j <= n; j++) {
    for (i = 1, count = 0; i <= j; i++) {
      if (n % i == 0)
        count++;
    }
    if (count == 8 && j % 2 == 1)
      number++;
  }
  printf("%d\n", number);
  return 0;
}