#include <stdio.h>
int main(void) {
  int H, R;
  scanf("%d %d", &H, &R);
  if (R + H > 0) {
    printf("1\n");
  } else if (R == -H) {
    printf("0\n");
  } else
    printf("-1\n");
  return 0;
}
