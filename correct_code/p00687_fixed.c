#include <stdio.h>
int main() {
  int n, a, b, i, c;
  while (scanf("%d %d %d", &n, &a, &b), n || a || b) {
    char d[2000000] = {1};
    for (i = c = 0; i <= n; i++) {
      if (d[i])
        d[i + a] = d[i + b] = 1;
      else
        c++;
    }
    printf("%d\n", c);
  }
  return 0;
}