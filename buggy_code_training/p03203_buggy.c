#include <stdio.h>

char c;
int f;
int nextInt();
int min(int a, int b);

int H, W, N, X, Y, low[200001], p, i, j;
int MAX = 524288;

int main(void) {
  H = nextInt();
  W = nextInt();
  N = nextInt();
  for (i = 2; i <= W; i++) {
    low[i] = MAX;
  }
  for (i = 0; i < N; i++) {
    X = nextInt();
    Y = nextInt();
    if (Y < low[X]) {
      low[X] = Y;
    }
  }
  for (i = 2; i <= W; i++) {
    if (low[i] == MAX) {
    } else if (low[i] + p == i) {
      p++;
    } else if (low[i] + p < i) {
      printf("%d\n", i - 1);
      return 0;
    }
  }
  printf("%d\n", W);
  return 0;
}

int nextInt() {
  f = 0;
  c = getchar();
  while ((c < '0') || ('9' < c)) {
    c = getchar();
  }
  while ((c >= '0') && (c <= '9')) {
    f = f * 10 + (c - '0');
    c = getchar();
  }
  return f;
}

int min(int a, int b) { return a > b ? b : a; }
