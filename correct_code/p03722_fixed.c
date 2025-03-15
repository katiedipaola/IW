#include <stdio.h>

#define ll long long
#define FALSE 0
#define TRUE 1

const ll INF = 1LL << 50;

int main(void) {
  int N, M;
  int a[2000], b[2000], ne[2000] = {FALSE};
  ll c[2000], dist[2000], ans;

  int i, loop;

  scanf("%d%d", &N, &M);
  for (i = 0; i < M; i++) {
    scanf("%d%d%lld", &a[i], &b[i], &c[i]);
    c[i] = -c[i];
  }

  for (i = 0; i < N; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;

  for (loop = 0; loop < N - 1; loop++) {
    for (i = 0; i < M; i++) {
      if (dist[a[i]] - 1 == INF)
        continue;

      if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
        dist[b[i] - 1] = dist[a[i] - 1] + c[i];
      }
    }
  }
  ans = dist[N - 1];

  for (loop = 0; loop < N; loop++) {
    for (i = 0; i < M; i++) {
      if (dist[a[i]] - 1 == INF)
        continue;

      if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
        dist[b[i] - 1] = dist[a[i] - 1] + c[i];
        ne[b[i] - 1] = TRUE;
      }

      if (ne[a[i] - 1] == TRUE) {
        ne[b[i] - 1] = TRUE;
      }
    }
  }
  if (ne[N - 1])
    printf("inf\n");
  else
    printf("%lld", -ans);

  return 0;
}