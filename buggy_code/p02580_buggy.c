#include <stdio.h>
int main() {
  int H, W, M, i, max1, max2, k1, cc, dd1, dd2;
  max1 = 0;
  max2 = 0;
  dd1 = 0;
  dd2 = 0;
  k1 = 0;
  scanf("%d %d %d", &H, &W, &M);

  int h[M], w[M], sw[H + W];

  for (i = 0; i < 2 * M; ++i) {
    sw[i] = 0;
  }

  for (i = 0; i < M; ++i) {
    scanf("%d %d", &h[i], &w[i]);
    sw[h[i] - 1]++;
    sw[H + w[i] - 1]++;
  }

  for (i = 0; i < H; ++i) {
    if (sw[i] > max1)
      max1 = sw[i];
  }
  for (i = 0; i < H; ++i) {
    if (sw[i] == max1)
      dd1++;
  }

  for (i = 0; i < W; ++i) {
    if (sw[H + i] > max2)
      max2 = sw[H + i];
  }
  for (i = 0; i < W; ++i) {
    if (sw[H + i] == max2)
      dd2++;
  }

  for (i = 0; i < M; ++i) {
    if (sw[h[i] - 1] == max1 && sw[H + w[i] - 1] == max2)
      k1++;
  }

  if (k1 == dd1 * dd2)
    printf("%d", max1 + max2 - 1);
  else
    printf("%d", max1 + max2);
  return 0;
}