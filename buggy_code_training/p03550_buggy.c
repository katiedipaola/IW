#include <math.h>
#include <stdint.h> // int64_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  scanf("%d %d %d %d", a1, a2, a3, a4);
  return 0;
}

int get_int5(int *a1, int *a2, int *a3, int *a4, int *a5) {
  scanf("%d %d %d %d %d", a1, a2, a3, a4, a5);
  return 0;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
int fget_array(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  return 0;
}
#define NUM_MAX 2000
#define INF (1e+9)

int main() {
  int num, xscore, yscore;
  get_int3(&num, &xscore, &yscore);
  static int arr[NUM_MAX];
  fget_array(arr, num);

  static int dp[NUM_MAX + 1][2];
  int last = arr[num - 1];
  int i, j;
  int prev_x = 0;
  int prev_y = 0;
  for (i = num - 1; i >= 0; i--) {
    int Y = (i ? arr[i - 1] : yscore);
    dp[i][0] = max(abs(Y - last), prev_y);
    // for (j = i+1; j < num; j++) {
    //     dp[i][0] = max(dp[i][0], dp[j][1]);
    // }
    prev_x = min(prev_x, dp[i][0]);

    int X = (i ? arr[i - 1] : xscore);
    dp[i][1] = min(abs(X - last), prev_x);
    prev_y = max(prev_y, dp[i][1]);
    // for (j = i+1; j < num; j++) {
    //     dp[i][1] = min(dp[i][1], dp[j][0]);
    // }
  }
  printf("%d\n", dp[0][0]);
}