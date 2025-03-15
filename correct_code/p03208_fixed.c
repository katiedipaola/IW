#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int main() {
  int N, K, h[100000], min = 1000000000, i;
  scanf("%d %d", &N, &K);
  for (i = 0; i < N; i++) {
    scanf("%d", &h[i]);
  }
  qsort(h, N, sizeof(int), compare_int);
  for (i = 0; i < N - K + 1; i++) {
    if (h[i + K - 1] - h[i] < min) {
      min = h[i + K - 1] - h[i];
    }
  }
  printf("%d", min);
}
