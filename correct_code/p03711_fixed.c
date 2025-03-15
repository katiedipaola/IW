#include <stdio.h>

int main() {
  int group[12] = {1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  int x, y;
  scanf("%d %d", &x, &y);
  if (group[x - 1] == group[y - 1]) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}