#include <stdio.h>

int main(int argc, char const *argv[]) {
  int width, hight, x, y, r;

  scanf("%d %d %d %d %d", width, hight, x, y, r);

  if (x + r > width || y + r > hight || x - r < 0 || y - r < 0) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
}
