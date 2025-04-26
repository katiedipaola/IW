#include <stdio.h>
#include <string.h>

int main() {
  int N, M;
  char U[11][300];
  char T[11];

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", U[i]);
  }

  scanf("%d", &M);

  int lock = 1, flag = 0;

  for (int i = 0; i < M; i++) {
    scanf("%s", T);
    flag = 0;
    for (int j = 0; j < N; j++) {
      // U[i] と T が一致するとき
      if (strcmp(T, U[i]) == 0) {
        flag = 1;
        break;
      }
    }
    // if (flag == 0) と同じ
    if (!flag) {
      printf("Unknown %s\n", T);
    } else if (lock) {
      printf("Opened by %s\n", T);
      lock = 0;
    } else {
      printf("Closed by %s\n", T);
      lock = 1;
    }
  }
  return 0;
}
