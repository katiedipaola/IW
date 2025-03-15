#include <stdio.h>
int main(void) {
  unsigned int c[3][3], i = 0, count = 0;

  for (i = 0; i <= 2; i++) {
    scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
  }

  i = 0;

  for (i = 0; i <= 2; i++) {
    if ((c[i][0] - c[(i + 1) % 3][0] == c[i][1] - c[(i + 1) % 3][1]) &&
        (c[i][0] - c[(i + 1) % 3][0] == c[i][2] - c[(i + 1) % 3][2])) {
      count++;
    }
    if ((c[0][i] - c[0][(i + 1) % 3] == c[1][i] - c[1][(i + 1) % 3]) &&
        (c[0][i] - c[0][(i + 1) % 3] == c[2][i] - c[2][(i + 1) % 3])) {
      count++;
    }
  }

  if (count == 6) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}