#include <stdio.h>
int main() {
  int n, k, ans;
  int p = 0;
  int q = 0;
  scanf("%d %d", &n, &k);

  int S[n];
  char s[n];
  scanf("%s", s);

  for (int i = 0; i < n; i++) {
    if ('L' == s[i]) {
      S[i] = 0;
    } else {
      S[i] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    if (S[i] != S[i + 1]) {
      p = p + 1;
    } else {
      q = q + 1;
    }
  }

  if (p <= 2 * k) {
    ans = n - 1;
  } else {
    ans = q + 2 * k;
  }

  printf("%d", ans);

  return 0;
}