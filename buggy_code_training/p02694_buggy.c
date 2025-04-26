#include <stdio.h>
int main() {
  int a, i = 1, b = 100;
  scanf("%d", &a);

  while (1) {
    b = b * 1.01;
    if (b >= a) {
      printf("%d\n", i);
      return 0;
    }
    i++;
  }
}
