#include <stdio.h>
int main(void) {

  int N;
  scanf("%d", &N);

  int p[10];
  int i;
  for (i = 0; i < N; i++) {
    scanf("%d", &p[i]);
  }
  int minnum, minp = p[0];

  for (i = 0; i < N; i++) {
    if (p[i] >= minp) {
      minp = p[i];
      minnum = i;
    }
  }

  int sum = 0;
  for (i = 0; i < N; i++) {
    if (i == minnum) {
      sum = sum + (p[i] / 2);
    } else {
      sum = sum + p[i];
    }
  }

  printf("%d", sum);
  return 0;
}
