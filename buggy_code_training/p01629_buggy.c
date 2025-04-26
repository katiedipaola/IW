/*
  AOJ 2517
  Title:Hotel
  @kankichi573
*/
#include <limits.h>
#include <stdio.h>

int N, D;
int charge[51][50];
int cheapest[51][50];
int times[51][50];
int result[50];
void calc_cheapest() {
  int i, j, min_;

  for (i = 0; i < D; i++) {
    min_ = INT_MAX;
    for (j = 0; j < N; j++)
      if (min_ > charge[j][i])
        min_ = charge[j][i];
    for (j = 0; j < N; j++)
      cheapest[j][i] = (min_ == charge[j][i]) ? (-1) : 0;
  }
}
int min_yadogae(int dat) {
  int i, min_;
  min_ = INT_MAX;
  for (i = 0; i < N; i++)
    if (times[i][dat] >= 0 && min_ > times[i][dat])
      min_ = times[i][dat];
  return (min_);
}
void calc_times() {
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < D; j++)
      times[i][j] = -2;
  for (i = 0; i < N; i++)
    if (cheapest[i][D - 1])
      times[i][D - 1] = 0;
  if (D == 1)
    return;

  for (j = D - 2; j >= 0; j--)
    for (i = 0; i < N; i++)
      if (cheapest[i][j])
        if (times[i][j + 1] >= 0)
          times[i][j] = times[i][j + 1];
        else
          times[i][j] = 1 + min_yadogae(j + 1);
}
void dump1() {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < D; j++)
      printf("%02d|", cheapest[i][j]);
    printf("\n");
  }
}
void dump2() {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < D; j++)
      printf("%02d|", times[i][j]);
    printf("\n");
  }
}
int cheapest_total() {
  int i, j, ret;
  ret = 0;
  for (j = 0; j < D; j++) {
    for (i = 0; i < N; i++)
      if (cheapest[i][j]) {
        ret += charge[i][j];
        break;
      }
  }
  return (ret);
}
int chepest_minimum(int d) {
  int i, ret, min_;

  min_ = INT_MAX;
  for (i = 0; i < N; i++)
    if (times[i][d] < min_) {
      min_ = times[i][d];
      ret = i;
    }
  return (ret);
}
void print_result() {
  int i, j, yg, pv;

  yg = min_yadogae(0) + 1;
  pv = -1;

  for (i = 0; i < D; i++)
    for (j = 0; i < N; j++)
      if ((j == pv && yg == times[j][i]) ||
          (j != pv && yg == times[j][i] + 1)) {
        printf("%d\n", j + 1);
        pv = j;
        yg = times[j][i];
        break;
      }
}
void solve() {
  int i, P, M;

  P = cheapest_total();
  M = min_yadogae(0);
  printf("%d %d\n", P, M);
  print_result();
}

main() {
  int i, j;

  scanf("%d %d", &N, &D);
  for (i = 0; i < N; i++)
    for (j = 0; j < D; j++)
      scanf("%d", &charge[i][j]);

  calc_cheapest();
  // dump1();
  // printf("--------\n");
  calc_times();
  // dump2();
  // printf("--------\n");
  solve();

  return (0);
}