#include <stdio.h>
int main(void) {
  int n;
  int p[50];
  int i, j;
  int a, b;
  int x, y;
  int c;
  int sum = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &p[i]);

  a = -1;
  b = -1;

  for (i = 0; i < n; i++) {
    if (p[i] != i + 1) {
      a = i;
      x = p[i];

      break;
    }
  }
  for (i = a + 1; i < n; i++) {
    if (p[i] != i + 1) {
      b = i;
      y = p[i];

      break;
    }
  }
  if (a == -1 && b == -1)
    printf("Yes");
  else {
    if (b == -1)
      printf("No");
    else {
      c = p[a];
      p[a] = p[b];
      p[b] = c;
      for (i = 0; i < n; i++) {
        if (p[i] != i + 1)
          break;
        sum++;
      }
      if (sum == n)
        printf("Yes");
      else
        printf("No");
    }
  }
  return 0;
}