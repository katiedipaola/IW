#include <stdio.h>
int main() {
  int A1, A2, A3;
  scanf("%d+%d+%d", &A1, &A2, &A3);
  if (A1 + A2 + A3 <= 22) {
    printf("win\n");
  } else if (A1 + A2 + A3 >= 22) {
    printf("bust\n");
  }
  return 0;
}