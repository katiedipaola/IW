#include <stdio.h>
#include <string.h>
int main(void) {
  int w, l, d;
  int n;
  int i, j, temp;
  int p[11];
  char t[11][21], tempt[21];

  scanf("%d", &n);
  while (n != 0) {
    for (i = 0; i < n; i++) {
      scanf("%s %d %d %d", t[i], &w, &l, &d);
      p[i] = w * 3 + d;
    }
    for (i = 0; i < n - 1; i++) {
      for (j = n - 1; j > i; j--) {
        if (p[j - 1] < p[j]) {
          temp = p[j - 1];
          p[j - 1] = p[j];
          p[j] = temp;
          strcpy(tempt, t[j - 1]);
          strcpy(t[j - 1], t[j]);
          strcpy(t[j], tempt);
        }
      }
    }
    for (i = 0; i < n; i++) {
      printf("%s,%d\n", t[i], p[i]);
    }
    scanf("%d", &n);
    if (n != 0) {
      printf("\n");
    }
  }
  return 0;
}