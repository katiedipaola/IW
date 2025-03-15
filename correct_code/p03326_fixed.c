#include <stdio.h>
#include <stdlib.h>

void quicksort(long long data[], int left, int right);

int main() {
  int n, m, i, j;
  long long x, y, z, ans = 0;
  long long a[8][1000] = {0};
  // long b[8]={0};
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%lld %lld %lld", &x, &y, &z);
    a[0][i] = x + y + z;
    a[1][i] = x + y - z;
    a[2][i] = x - y + z;
    a[3][i] = x - y - z;
    a[4][i] = -x + y + z;
    a[5][i] = -x + y - z;
    a[6][i] = -x - y + z;
    a[7][i] = -x - y - z;
  }
  for (i = 0; i < 8; i++) {
    quicksort(a[i], 0, n - 1);
    long long kari = 0;
    for (j = 0; j < m; j++)
      kari += a[i][j];
    if (kari > ans)
      ans = kari;
  }
  printf("%lld", ans);
}

void quicksort(long long data[], int left, int right) {
  int i, j;
  long long std, work;
  if (left < right) {
    i = left, j = right;
    std = data[(i + j) / 2]; //基準
    do {
      while (data[i] > std)
        i++;
      while (data[j] < std)
        j--;
      if (i <= j) {
        if (i < j) {
          work = data[i];
          data[i] = data[j];
          data[j] = work;
        }
        i++;
        j--;
      }
    } while (i <= j);
    if (left < j)
      quicksort(data, left, j);
    if (i < right)
      quicksort(data, i, right);
  }
}