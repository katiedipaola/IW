#include <stdio.h>

int main(void) {
  int N, A;
  scanf("%d%d", &N, &A);

  int flag = 0;
  for (int i = 0; i <= A; i++) {
    if (N <= A || (N - i) % 500 == 0) {
      flag = 1;
      break;
    }
  }

  if (flag == 1) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}