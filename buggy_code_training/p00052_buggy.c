#include <stdio.h>
#include <string.h>

int main() {
  int i, five, ans;
  do {
    scanf("%d", &i);
    if (i == 0)
      break;
    for (five = 5, ans = 0; five < i; five *= 5)
      ans += i / five;
    printf("%d\n", ans);
  } while (1);
  return 0;
}