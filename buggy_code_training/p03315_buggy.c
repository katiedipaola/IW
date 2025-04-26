#include <stdio.h>

int main(void) {
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (getchar() == "+")
      ans++;
    else
      ans--;
  }
  printf("%d\n", ans);
  return 0;
}