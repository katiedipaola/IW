#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n / 10 == 9) {
    printf("Yes");
  } else if (n - n / 10 * 10 == 9) {
    printf("Yes");
  } else {
    printf("No");
  }
}