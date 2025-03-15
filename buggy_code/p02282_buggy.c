#include <stdio.h>
#define MAX 40

int n, pos = 0;
int cout = 0;
int Pre[MAX], In[MAX], final[MAX];

int distance(int first, int key) {
  int i, count = 0;

  for (i = first; i < MAX; i++) {
    if (In[i] != key)
      count++;
    else
      break;
  }

  return count;
}

int solve(int l, int r) {

  int root, d;
  if (l - r >= 0)
    return -1;

  root = Pre[pos];
  pos++;

  d = distance(0, root);
  if (d > n)
    return -1;

  solve(l, d);
  solve(d + 1, r);

  final[cout++] = root;
  return 0;
}

int main() {
  int m, i;
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    Pre[i] = m;
  }

  for (i = 0; i < n; i++) {
    scanf("%d", &m);
    In[i] = m;
  }
  solve(0, n);

  printf("%d", final[0]);

  for (i = 1; i < n; i++)
    printf("%d", final[i]);
  printf("\n");

  return 0;
}