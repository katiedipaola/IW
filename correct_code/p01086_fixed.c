#include <stdio.h>
#include <string.h>

int NextInt() {
  int d;
  scanf("%d", &d);
  return d;
}

int main() {
  int i, j, n;
  int t, u;
  char s[11];
  int a[41];
  int c;
  int b[5] = {5, 7, 5, 7, 7};
  int ans;

  while (1) {
    n = NextInt();
    if (n == 0) {
      break;
    }
    for (i = 0; i < n; i++) {
      scanf("%s", s);
      a[i] = strlen(s);
    }
    ans = n;
    for (j = 0; j < n; j++) {
      c = 0;
      t = 0;
      u = j + 1;
      for (i = j; i < n; i++) {
        t += a[i];
        if (t > b[c]) {
          t = a[i];
          c = 0;
          u = i + 1;
        }
        if (t == b[c]) {
          t = 0;
          c++;
          if (c == 5) {
            break;
          }
        }
      }
      if (u < ans) {
        ans = u;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}