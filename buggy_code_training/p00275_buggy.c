#include <stdio.h>
int main() {
  int N;
  int p[20] = {0};
  int i, j, temp, s;
  int ba = 0;
  char c[200];
  while (1) {
    scanf("%d", &N);
    if (N == 0) {
      break;
    }
    ba = 0;
    for (i = 0; i < 10; i++) {
      p[i] = 0;
    }
    scanf("%s", c);
    for (j = 0; j < 100; j++) {
      s = j % N;
      if (c[j] == 'M') {
        p[s]++;
      } else if (c[j] == 'S') {
        ba = ba + p[s];
        p[s] = 0;
        ba++;
      } else if (c[j] == 'L') {
        p[s] = p[s] + ba;
        ba = 0;
        p[s]++;
      }
    }
    for (i = 0; i < N; i++) {
      for (j = N - 1; j > i; j--) {
        if (p[i] > p[j]) {
          temp = p[i];
          p[i] = p[j];
          p[j] = temp;
        }
      }
    }
    for (i = 0; i < N; i++) {
      printf(" %d", p[i]);
    }
    printf(" %d", ba);
  }
  return 0;
}