#include <stdio.h>

void merge_sort(int x[], int n) {
  static int y[100001] = {};
  if (n <= 1)
    return;
  merge_sort(&(x[0]), n / 2);
  merge_sort(&(x[n / 2]), (n + 1) / 2);

  int i, p, q;
  for (i = 0, p = 0, q = n / 2; i < n; i++) {
    if (p >= n / 2)
      y[i] = x[q++];
    else if (q >= n)
      y[i] = x[p++];
    else
      y[i] = (x[p] < x[q]) ? x[p++] : x[q++];
  }
  for (i = 0; i < n; i++)
    x[i] = y[i];
}

int main() {
  const int sup = 1 << 30, inf = -sup;
  int i, n[4] = {}, N, x, y, p[4][100001], max[2] = {inf, inf},
         min[2] = {sup, sup};
  char d;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d %d %c", &x, &y, &d);
    if (d == 'R') {
      p[0][n[0]++] = x * 2;
      if (y * 2 > max[1])
        max[1] = y * 2;
      if (y * 2 < min[1])
        min[1] = y * 2;
    } else if (d == 'L') {
      p[1][n[1]++] = x * 2;
      if (y * 2 > max[1])
        max[1] = y * 2;
      if (y * 2 < min[1])
        min[1] = y * 2;
    } else if (d == 'U') {
      p[2][n[2]++] = y * 2;
      if (x * 2 > max[0])
        max[0] = x * 2;
      if (x * 2 < min[0])
        min[0] = x * 2;
    } else {
      p[3][n[3]++] = y * 2;
      if (x * 2 > max[0])
        max[0] = x * 2;
      if (x * 2 < min[0])
        min[0] = x * 2;
    }
  }
  merge_sort(p[0], n[0]);
  merge_sort(p[1], n[1]);
  merge_sort(p[2], n[2]);
  merge_sort(p[3], n[3]);

  int t[4][2];
  if (n[1] > 0 && p[1][n[1] - 1] > max[0] &&
      (n[0] == 0 || p[1][n[1] - 1] > p[0][n[0] - 1])) {
    if (max[0] == inf)
      t[0][0] = sup;
    else
      t[0][0] = p[1][n[1] - 1] - max[0];
    if (n[0] > 0 && t[0][0] > (p[1][n[1] - 1] - p[0][n[0] - 1]) / 2)
      t[0][0] = (p[1][n[1] - 1] - p[0][n[0] - 1]) / 2;
  } else
    t[0][0] = 0;
  if (n[0] > 0) {
    if (max[0] <= p[0][n[0] - 1])
      t[0][1] = 0;
    else
      t[0][1] = max[0] - p[0][n[0] - 1];
    if (n[1] > 0 && t[0][1] < (p[1][n[1] - 1] - p[0][n[0] - 1]) / 2)
      t[0][1] = (p[1][n[1] - 1] - p[0][n[0] - 1]) / 2;
  } else
    t[0][1] = sup;

  if (n[0] > 0 && p[0][0] < min[0] && (n[1] == 0 || p[0][0] < p[1][0])) {
    if (min[0] == sup)
      t[1][0] = sup;
    else
      t[1][0] = min[0] - p[0][0];
    if (n[1] > 0 && t[1][0] > (p[1][0] - p[0][0]) / 2)
      t[1][0] = (p[1][0] - p[0][0]) / 2;
  } else
    t[1][0] = 0;
  if (n[1] > 0) {
    if (min[0] >= p[1][0])
      t[1][1] = 0;
    else
      t[1][1] = p[1][0] - min[0];
    if (n[0] > 0 && t[1][1] < (p[1][0] - p[0][0]) / 2)
      t[1][1] = (p[1][0] - p[0][0]) / 2;
  } else
    t[1][1] = sup;

  if (n[3] > 0 && p[3][n[3] - 1] > max[1] &&
      (n[2] == 0 || p[3][n[3] - 1] > p[2][n[2] - 1])) {
    if (max[1] == inf)
      t[2][0] = sup;
    else
      t[2][0] = p[3][n[3] - 1] - max[1];
    if (n[2] > 0 && t[2][0] > (p[3][n[3] - 1] - p[2][n[2] - 1]) / 2)
      t[2][0] = (p[3][n[3] - 1] - p[2][n[2] - 1]) / 2;
  } else
    t[2][0] = 0;
  if (n[2] > 0) {
    if (max[1] <= p[2][n[2] - 1])
      t[2][1] = 0;
    else
      t[2][1] = max[1] - p[2][n[2] - 1];
    if (n[3] > 0 && t[2][1] < (p[3][n[3] - 1] - p[2][n[2] - 1]) / 2)
      t[2][1] = (p[3][n[3] - 1] - p[2][n[2] - 1]) / 2;
  } else
    t[2][1] = sup;

  if (n[2] > 0 && p[2][0] < min[1] && (n[3] == 0 || p[2][0] < p[3][0])) {
    if (min[1] == sup)
      t[3][0] = sup;
    else
      t[3][0] = min[1] - p[2][0];
    if (n[3] > 0 && t[3][0] > (p[3][0] - p[2][0]) / 2)
      t[3][0] = (p[3][0] - p[2][0]) / 2;
  } else
    t[3][0] = 0;
  if (n[3] > 0) {
    if (min[1] >= p[3][0])
      t[3][1] = 0;
    else
      t[3][1] = p[3][0] - min[1];
    if (n[2] > 0 && t[3][1] < (p[3][0] - p[2][0]) / 2)
      t[3][1] = (p[3][0] - p[2][0]) / 2;
  } else
    t[3][1] = sup;

  int j;
  long long ans = (long long)sup * sup, tmp[4];
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 2; j++) {
      if (t[i][j] == sup)
        continue;
      tmp[0] = max[0];
      if (n[0] > 0 && tmp[0] < p[0][n[0] - 1] + t[i][j])
        tmp[0] = p[0][n[0] - 1] + t[i][j];
      if (n[1] > 0 && tmp[0] < p[1][n[1] - 1] - t[i][j])
        tmp[0] = p[1][n[1] - 1] - t[i][j];
      tmp[1] = min[0];
      if (n[0] > 0 && tmp[1] > p[0][0] + t[i][j])
        tmp[1] = p[0][0] + t[i][j];
      if (n[1] > 0 && tmp[1] > p[1][0] - t[i][j])
        tmp[1] = p[1][0] - t[i][j];
      tmp[2] = max[1];
      if (n[2] > 0 && tmp[2] < p[2][n[2] - 1] + t[i][j])
        tmp[2] = p[2][n[2] - 1] + t[i][j];
      if (n[3] > 0 && tmp[2] < p[3][n[3] - 1] - t[i][j])
        tmp[2] = p[3][n[3] - 1] - t[i][j];
      tmp[3] = min[1];
      if (n[2] > 0 && tmp[3] > p[2][0] + t[i][j])
        tmp[3] = p[2][0] + t[i][j];
      if (n[3] > 0 && tmp[3] > p[3][0] - t[i][j])
        tmp[3] = p[3][0] - t[i][j];

      if (ans > (tmp[0] - tmp[1]) * (tmp[2] - tmp[3]))
        ans = (tmp[0] - tmp[1]) * (tmp[2] - tmp[3]);
    }
  }

  printf("%.2Lf\n", (long double)ans / 4.0);
  fflush(stdout);
  return 0;
}