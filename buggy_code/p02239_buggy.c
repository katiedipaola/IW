#include <stdio.h>
#define MAX 102
#define WHITE 0
#define BLACK 1
#define GRAY 2
#define NIL -1

void init();

int n, head = 0, tail = 0, color[MAX];
int d[MAX], edge[MAX], G[MAX][MAX];

void init() {
  int i;

  for (i = 0; i <= n; i++) {
    color[i] = WHITE;
    d[i] = 10000000;
  }
}

/*void Enqueue(int x){
  if((head == 1 && tail == length) || head == tail+1){
    return NIL;
  }

  Q[tail] = x;

  if(tail == length){
    tail = 1;
  } else {
    tail = tail+1;
  }

  }*/

void Enqueue(int *Q, int x) {

  if (tail == n) {
    tail = 1;
  } else {
    tail += 1;
  }

  Q[tail] = x;
}

int Dequeue(int *Q) {
  if (head == n) {
    head = 1;
  } else {
    head++;
  }
  return Q[head];
}

void BFS() {
  int i, s = 1, u, j = 0;
  int Q[101];
  init();

  color[s] = GRAY;
  d[s] = 0;
  for (i = 0; i <= n; i++) {
    Q[i] = 0;
  }
  Enqueue(Q, s);

  while (head != tail) {
    u = Dequeue(Q);

    for (i = 1; i <= n; i++) {
      if (color[i] == WHITE && G[u][i] == 10) {
        color[i] = GRAY;
        d[i] = d[u] + 1;
        Enqueue(Q, i);
      }
    }
    color[u] = BLACK;
    j++;
  }
}

int main() {

  int i, j, k = 0, vertex, number;

  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    scanf("%d %d", &vertex, &edge[i]);
    for (j = 1; j <= edge[i]; j++) {
      scanf("%d", &number);
      G[vertex][number] = 10;
    }
  }

  /*for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      printf("%d ",G[i][j]);
    }
    printf("\n");
    }*/

  BFS();

  for (i = 1; i <= n; i++) {
    if (d[i] == 10000000) {
      printf("%d %d\n", i, -1);
    } else {
      printf("%d %d\n", i, d[i]);
    }

    return 0;
  }

  return 0;
}