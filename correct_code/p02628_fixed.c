#include <stdio.h>

void sort(int n, int *p) {
  int i, j, temp;

  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
      if (p[i] > p[j]) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
}

int main(void) {
  int n, k;
  int i, sum = 0;

  scanf("%d %d", &n, &k);

  int p[n];

  for (i = 0; i < n; i++)
    scanf("%d", &p[i]);

  sort(n, p);

  for (i = 0; i < k; i++) {
    sum += p[i];
  }

  printf("%d", sum);

  return 0;
}