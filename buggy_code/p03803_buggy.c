#include <stdio.h>
#include <string.h>
char a[10000];
int b[10000];
int main() {
  int i, j, k, n, m;
  scanf("%d%d", &n, &m);
  if (n == 1 && m != 1)
    printf("Allice");
  else if (m == 1 && n != 1)
    printf("Bob");
  else if (n > m)
    printf("Allice");
  else if (n < m)
    printf("Bob");
  else
    printf("Draw");
  return 0;
}