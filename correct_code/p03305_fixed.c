#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  struct List *next;
  int v, cost, tmp;
} list;

typedef struct {
  long long key;
  int id;
} data;

typedef struct {
  data *obj;
  int size;
} min_heap;

void push(data x, min_heap *h) {
  int i = h->size;
  data tmp;
  h->obj[(h->size)++] = x;
  while (1) {
    if (i == 0)
      break;
    else if (h->obj[i].key < h->obj[(i - 1) / 2].key) {
      tmp = h->obj[(i - 1) / 2];
      h->obj[(i - 1) / 2] = h->obj[i];
      h->obj[i] = tmp;
      i = (i - 1) / 2;
    } else
      break;
  }
}

data pop(min_heap *h) {
  int i = 0, j;
  data output = h->obj[0], tmp;
  h->obj[0] = h->obj[--(h->size)];
  while (1) {
    if (i * 2 + 1 >= h->size)
      break;
    else if (i * 2 + 2 >= h->size)
      j = i * 2 + 1;
    else if (h->obj[i * 2 + 1].key < h->obj[i * 2 + 2].key)
      j = i * 2 + 1;
    else
      j = i * 2 + 2;
    if (h->obj[j].key < h->obj[i].key) {
      tmp = h->obj[j];
      h->obj[j] = h->obj[i];
      h->obj[i] = tmp;
      i = j;
    } else
      break;
  }
  return output;
}

long long *dijkstra(list **adj, int s, int n, int m) {
  int i, *prev = (int *)malloc(sizeof(int) * (n + 1));
  long long *dist = (long long *)malloc(sizeof(long long) * (n + 1));
  for (i = 1; i <= n; i++) {
    dist[i] = (long long)1 << 60;
    prev[i] = 0;
  }
  dist[s] = 0;
  prev[s] = -s;

  int u, w;
  list *p;
  data d;
  min_heap h;
  h.obj = (data *)malloc(sizeof(data) * (m * 2 + 1));
  h.size = 0;
  d.key = 0;
  d.id = s;
  push(d, &h);
  while (h.size > 0) {
    u = pop(&h).id;
    if (prev[u] > 0)
      continue;
    prev[u] *= -1;
    for (p = adj[u]; p != NULL; p = p->next) {
      w = p->v;
      if (dist[u] + p->cost < dist[w]) {
        dist[w] = dist[u] + p->cost;
        prev[w] = -u;
        d.key = dist[w];
        d.id = w;
        push(d, &h);
      }
    }
  }

  free(prev);
  free(h.obj);
  return dist;
}

int main() {
  int i, n, m, s, t, u, w, a, b;
  scanf("%d %d %d %d", &n, &m, &s, &t);
  list **adj = (list **)malloc(sizeof(list *) * (n + 1)),
       *e = (list *)malloc(sizeof(list) * m * 2);
  for (i = 1; i <= n; i++)
    adj[i] = NULL;
  for (i = 0; i < m; i++) {
    scanf("%d %d %d %d", &u, &w, &a, &b);
    e[i * 2].v = w;
    e[i * 2 + 1].v = u;
    e[i * 2].cost = a;
    e[i * 2 + 1].cost = a;
    e[i * 2].tmp = b;
    e[i * 2 + 1].tmp = b;
    e[i * 2].next = adj[u];
    e[i * 2 + 1].next = adj[w];
    adj[u] = &(e[i * 2]);
    adj[w] = &(e[i * 2 + 1]);
  }

  long long *dist[2];
  dist[0] = dijkstra(adj, s, n, m);
  for (i = 0; i < m * 2; i++)
    e[i].cost = e[i].tmp;
  dist[1] = dijkstra(adj, t, n, m);

  data d;
  min_heap h;
  h.size = 0;
  h.obj = (data *)malloc(sizeof(data) * (n + 1));
  for (i = 1; i <= n; i++) {
    d.key = dist[0][i] + dist[1][i];
    d.id = i;
    push(d, &h);
  }

  d.id = 0;
  for (i = 0; i < n; i++) {
    while (d.id <= i)
      d = pop(&h);
    printf("%lld\n", (long long)1000000000000000 - d.key);
  }
  fflush(stdout);
  return 0;
}