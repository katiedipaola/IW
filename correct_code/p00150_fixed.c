#include <stdio.h>

#define N 10000

int tbl[N + 1] = {0};
size_t tbln = 0;

/** Application main entry point. */
int main(int argc, char *argv[]) {
  int i, j;

  for (j = 2; j <= N; ++j) {
    if (tbl[j])
      continue;

    for (i = j * 2; i <= N; i += j) {
      tbl[i] = 1;
    }
  }
  for (i = 2; i <= N - 2; ++i) {
    if (!tbl[i] && !tbl[i + 2]) {
      tbl[tbln++] = i + 2;
    }
  }

  for (;;) {
    int n;

    scanf("%d", &n);
    if (!(n))
      break;

    for (i = 1; i < tbln && tbl[i] <= n; ++i)
      ;

    printf("%d %d\n", tbl[i - 1] - 2, tbl[i - 1]);
  }

  return (0);
}