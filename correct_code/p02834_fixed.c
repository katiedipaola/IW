#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  struct List *next;
  int v;
} list;

int main() {
  int i, u, w, N, T, A;
  scanf("%d %d %d", &N, &T, &A);
  list **adj = (list **)malloc(sizeof(list *) * (N + 1)),
       *d = (list *)malloc(sizeof(list) * (N - 1) * 2);
  for (i = 1; i <= N; i++)
    adj[i] = NULL;
  for (i = 0; i < N - 1; i++) {
    scanf("%d %d", &u, &w);
    d[i * 2].v = w;
    d[i * 2 + 1].v = u;
    d[i * 2].next = adj[u];
    d[i * 2 + 1].next = adj[w];
    adj[u] = &(d[i * 2]);
    adj[w] = &(d[i * 2 + 1]);
  }

  int dist[2][100001] = {}, q[100001], head, tail;
  list *p;
  dist[0][A] = 1;
  q[0] = A;
  for (head = 0, tail = 1; head < tail; head++) {
    u = q[head];
    for (p = adj[u]; p != NULL; p = p->next) {
      w = p->v;
      if (dist[0][w] == 0) {
        dist[0][w] = dist[0][u] + 1;
        q[tail++] = w;
      }
    }
  }
  dist[1][T] = 1;
  q[0] = T;
  for (head = 0, tail = 1; head < tail; head++) {
    u = q[head];
    for (p = adj[u]; p != NULL; p = p->next) {
      w = p->v;
      if (dist[1][w] == 0 && dist[1][u] + 1 < dist[0][w]) {
        dist[1][w] = dist[1][u] + 1;
        q[tail++] = w;
      }
    }
  }

  int max = 0;
  for (i = 1; i <= N; i++)
    if (dist[1][i] > 0 && dist[0][i] - 2 > max)
      max = dist[0][i] - 2;
  printf("%d\n", max);
  fflush(stdout);
  return 0;
}