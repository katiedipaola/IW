#include <stdio.h>
#include <string.h>
int main() {
  char ch[21];
  char ring[21];
  int n, i, j, count = 0;
  scanf("%s\n%d\n", &ch, &n);
  for (i = 0; i < n; i++) {
    scanf("%s\n", &ring);
    for (j = 0; j < 10; j++) {
      ring[10 + j] = ring[j];
    }
    ring[10 + j] = '\0';
    if (strstr(ring, ch))
      count++;
  }
  printf("%d\n", count);
  return 0;
}