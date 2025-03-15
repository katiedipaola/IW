#include <stdio.h>

void run(void) {
  int i, j, s, flag = 0, N;
  scanf("%d", &N);
  for (i = 0; i <= N / 4 && flag == 0; ++i) {
    for (j = 0; j <= N / 7 && flag == 0; ++j) {
      s = 4 * i + 7 * j;
      if (s == N) {
        flag = 1;
        printf("Yes");
      }
    }
  }
  if (flag == 0)
    printf("No\n");
}
int main() {
  run();
  return 0;
}