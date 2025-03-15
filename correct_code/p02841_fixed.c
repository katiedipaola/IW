#include <stdio.h>

int main() {

  int M_1, D_1, M_2, D_2;

  scanf("%d %d", &M_1, &D_1);
  scanf("%d %d", &M_2, &D_2);

  if (M_1 != M_2 && D_1 > D_2) {
    printf("1");
  } else {
    printf("0");
  }
  return 0;
}
