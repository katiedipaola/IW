// https://atcoder.jp/contests/abc118/tasks/abc118_b

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
  int n, m, o, ans = 0, buf;
  scanf("%d%d", &n, &m);
  int count[m];

  // 初期化
  for (int i = 0; i < m; i++)
    count[i] = 0;

  // N人に対して聞く
  for (int i = 0; i < n; i++) {
    scanf("%d", &o);
    for (int j = 0; j < o; j++) {
      scanf("%d", &buf);
      count[buf - 1]++;
    }
  }

  for (int i = 0; i < m; i++) {
    if (count[i] == n) {
      ans++;
    }
  }
  printf("%d", ans);

  return 0;
}
