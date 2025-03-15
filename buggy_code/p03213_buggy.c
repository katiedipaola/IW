#include <stdio.h>
int main() {
  int n, i, j, k, c = 0, b[110] = {};
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    k = i;
    for (j = 2; j <= k; j++) {
      while (k % j == 0) {
        b[j]++;
        k /= j;
      }
    }
    // if(k>1)b[k]++;
  }
  // for(i=0;i<=10;i++)printf("%d %d\n",i,b[i]);
  for (i = 2; i <= n; i++) {
    if (b[i] < 4)
      continue;
    for (j = i + 1; j <= n; j++) {
      if (b[j] < 4)
        continue;
      for (k = 2; k <= n; k++) {
        if (i == k || j == k || b[k] < 2)
          continue;
        c++;
      }
    }
  }
  for (i = 2; i <= n; i++) {
    if (b[i] < 14)
      continue;
    for (j = 2; j <= n; j++) {
      if (i == j || b[j] < 4)
        continue;
      c++;
    }
  }
  for (i = 2; i <= n; i++) {
    if (b[i] < 24)
      continue;
    for (j = 2; j <= n; j++) {
      if (i == j || b[j] < 2)
        continue;
      c++;
    }
  }
  for (i = 2; i <= n; i++) {
    if (b[i] < 75)
      continue;
    c++;
  }
  printf("%d\n", c);
  return 0;
}
