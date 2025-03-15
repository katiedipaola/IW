#include <stdio.h>

int main() {
  int n, q, i, j, min, max;
  scanf("%d %d", &n, &q);
  char s[200001];
  scanf("%s", s);
  char t[200001], d[200001];
  for (i = 0; i < q; ++i) {
    scanf("\n%c %c", &t[i], &d[i]);
  }
  for (i = q - 1, min = 0, max = n - 1; i >= 0; --i) {
    switch (d[i]) {
    case 'R':
      if (t[i] == s[max]) {
        max--;
      }
      if (min > 0 && t[i] == s[min - 1]) {
        min--;
      }
      break;
    case 'L':
      if (t[i] == s[min]) {
        min++;
      }
      if (max < n - 1 && t[i] == s[max + 1]) {
        max++;
      }
      break;
    }
  }
  printf("%d\n", max - min - 1);
}