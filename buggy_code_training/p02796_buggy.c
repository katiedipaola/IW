#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100002

typedef struct {
  int X;
  int L;
  int end;
} robo;
int compare_int(const void *a, const void *b) {
  return ((robo *)a)->end - ((robo *)b)->end;
}
int main() {
  robo robot[MAX];
  int N;
  scanf("%d", &N);
  int X[MAX], L[MAX];
  int end[MAX];
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &robot[i].X, &robot[i].L);
    robot[i].end = robot[i].X + robot[i].L;
  }
  qsort(robot, N, sizeof(robo), compare_int);
  int ans = 1, tmp = robot[1].X + robot[1].L;
  for (int i = 2; i <= N; i++) {
    if (tmp <= robot[i].X - robot[i].L) {
      tmp = robot[i].X + robot[i].L;
      ans++;
    }
  }
  printf("%d", ans);
}
