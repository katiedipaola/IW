#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int n, t, x, ans = 10000, r[200010] = {0};
  char s[1000], T[1000];
  scanf("%s\n", s);
  scanf("%s", T);
  for (int i = 0; i + strlen(T) < strlen(s); i++) {
    int re = 0;
    for (int j = 0; j < strlen(T); j++)
      if (s[i + j] != T[j])
        re++;
    if (re < ans)
      ans = re;
  }
  printf("%d", ans);
  return 0;
}