#include <stdio.h>

int main(void) {
  int x, y;
  int i;
  int flag = 0;

  scanf("%d", &x);
  scanf("%d", &y);

  for (i = 0; i < (x + 1); i++) {
    if ((x - i) * 2 + i * 4 == y) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    printf("Yes");
  } else {
    printf("No");
  }

  printf("\n");
  return 0;
}
