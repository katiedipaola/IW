#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n / 10 == 9) {
    printf("yes");
  } else if (n - n / 10 * 10 == 9) {
    printf("yes");
  } else {
    printf("no");
  }
}