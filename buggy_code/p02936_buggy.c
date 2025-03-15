#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define input_i(x) scanf("%d", &x)

#define N_SIZE 200001
#define Q_SIZE 200001

int *To[N_SIZE];
int To_size[N_SIZE];
int Ans[N_SIZE];

void dfs(int v, int p) {
  int i, u;
  for (i = 0; i < To_size[v]; i++) {
    u = To[v][i];
    if (u == p)
      continue;
    Ans[u] += Ans[v];
    dfs(u, v);
  }
}

int main(int argc, char const *argv[]) {
  int N, Q, a, b, p, x, i;
  input_i(N);
  input_i(Q);
  for (i = 0; i < N - 1; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    if (To_size[a] == 0)
      To[a] = (int *)malloc(sizeof(int));
    else
      To[a] = (int *)realloc(To[a], sizeof(int) * (To_size[a] + 1));
    To[a][To_size[a]] = b;
    To_size[a]++;
    if (To_size[b] == 0)
      To[b] = (int *)malloc(sizeof(int));
    else
      To[b] = (int *)realloc(To[b], sizeof(int) * (To_size[b] + 1));
    To[b][To_size[b]] = a;
    To_size[b]++;
  }
  for (i = 0; i < Q; i++) {
    input_i(p);
    input_i(x);
    p--;
    Ans[p] += x;
  }
  dfs(0, -1);
  for (i = 0; i < N; i++)
    printf("%d ", Ans[i]);
  printf("\b\n");
  return 0;
}
