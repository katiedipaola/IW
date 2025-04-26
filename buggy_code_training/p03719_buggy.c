#include <stdio.h>

int main(void) {
  int num[3];
  for (int i = 0; i < 3; i++) {
    scanf("%d", &num[i]);
  }
  if (num[0] <= num[2] && num[2] <= num[1]) {
    printf("yes");
  } else {
    printf("no");
  }
  return 0;
}