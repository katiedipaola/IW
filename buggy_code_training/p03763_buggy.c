#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 60
#define MAXS 3600
int n;
char *strings[MAXN];
int min(const int a, const int b) { return a > b ? a : b; }

void read_str(int idx) {
  char buf[MAXN];
  fgets(buf, MAXN, stdin);
  int len = strlen(buf);
  if (buf[len - 1] == '\n')
    buf[--len] = '\0';
  strings[idx] = strdup(buf);
}
int solve(char *res) {
  int t = 0;
  int cnt[26];
  for (int i = 0; i < 26; i++)
    cnt[i] = 1e9;
  for (int i = 0; i < n; i++) {
    int currcnt[26] = {0};
    int len = strlen(strings[i]);
    for (int j = 0; j < len; j++)
      currcnt[strings[i][j] - 'a']++;
    for (int j = 0; j < 26; j++)
      cnt[i] = min(cnt[i], currcnt[i]);
  }
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < cnt[i]; j++)
      cnt[t++] = i + 'a';
  cnt[t] = '\0';
  return t;
}
int main(void) {
  scanf("%d\n", &n);
  char res[MAXS];
  for (int i = 0; i < n; i++)
    read_str(i);
  solve(res);
  puts(res);
  return 0;
}