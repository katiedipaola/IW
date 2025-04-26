#include <limits.h>
#include <math.h>
#include <stdio.h>

#define N (1 << 20)

int seg[N << 1];
void init(void) {
  int i;
  for (i = 0; i < (N << 1); i++) {
    seg[i] = 0;
  }
}
int find(int a, int b, int x, int l, int r) {
  if (a >= r || l >= b)
    return (0);
  if (a <= l && r <= b)
    return (seg[x]);
  return (find(a, b, x + x + 1, l, l + r >> 1) +
          find(a, b, x + x + 2, l + r >> 1, r));
}
void update(int x, int v) {
  seg[x += N - 1] = v;
  while (x) {
    x = x - 1 >> 1;
    seg[x] = seg[x + x + 1] + seg[x + x + 2];
  }
}

int main(void) {
  int n, q;

  init();
  scanf("%d %d", &n, &q);
  while (q--) {
    int qid, pos, val;
    scanf("%d %d %d", &qid, &pos, &val);
    if (qid)
      printf("%d\n", find(pos, val + 1, 0, 0, N));
    else
      update(pos, val);
  }
  return (0);
}