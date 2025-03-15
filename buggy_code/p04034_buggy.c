#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
  int N, M;
  int x, y;
  int check[100001] = {0};
  int count[100001];
  long ans = 0;
  long i, j;

  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; i++)
    count[i] = 1;
  check[1] = 1;
  for (i = 1; i <= M; i++) {
    scanf("%d %d", &x, &y);
    check[y] = check[x];
    count[x]--;
    count[y]++;
    if (count[x] == 0)
      check[x] = 0;
  }
  for (i = 1; i <= N; i++) {
    // printf("%d ", check[i]);
    ans += check[i];
  }
  // printf("\n");

  printf("%ld\n", ans);

  return 0;
}