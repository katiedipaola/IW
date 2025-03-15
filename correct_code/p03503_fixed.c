
#include <stdio.h>

int ans = -1000000000, data1[100][15], data2[100][15], data[15], n;

void calc_score(void) {
  int index = 0, score = 0, cnt = 0;
  for (int i = 0; i < 10; i++) {
    if (data[i] == 0) {
      cnt++;
    }
  }
  if (cnt == 10) {
    return;
  }
  for (int i = 0; i < n; i++) {
    index = 0;
    for (int j = 0; j < 10; j++) {
      if (data1[i][j] == 1 && data[j] == 1) {
        index += 1;
      }
    }
    score += data2[i][index];
  }

  if (score > ans) {
    ans = score;
  }
}

void set_data(int pos) {
  if (pos == 10) {
    calc_score();
    return;
  }
  if (pos != 10) {
    data[pos] = 0;
    set_data(pos + 1);
    data[pos] = 1;
    set_data(pos + 1);
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      scanf("%d", &data1[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 11; j++) {
      scanf("%d", &data2[i][j]);
    }
  }
  set_data(0);
  printf("%d\n", ans);
  return 0;
}