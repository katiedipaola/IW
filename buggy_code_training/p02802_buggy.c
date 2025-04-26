#include <stdio.h>
#include <string.h>
int a[100001], b[100001];
char c[4] = {"WA"};
int main() {
  int ac = 0, wa = 0;
  int n, m, i, num;
  char s[4];
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &num);
    scanf("%s", s), getchar();
    if (!a[num]) {
      if (!strcmp(s, c))
        b[num]++;
      else
        ac++, a[num]++;
    }
  }
  for (i = 1; i <= n; i++)
    if (a[num] && b[num])
      wa += b[num];
  printf("%d %d\n", ac, wa);
  return 0;
}
