#include <stdio.h>
int Search(int key, int A[], int n) {
  int i;
  i = 0;
  A[n] = key;
  while (A[i] != key) {
    i++;
    if (i == n) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, i, S[10000], q, key, sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (Search(key, S, n)) {
      sum++;
    }
  }
  printf("%d\n", sum);
  return 0;
}
