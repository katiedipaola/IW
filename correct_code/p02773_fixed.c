#include <stdio.h>
#include <string.h>
int R = 1, C = 1, H[2000010], N[2000010];
char S[200010][20];
//評価関数（いまはMIN）
int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return strcmp(S[N[H[a]]], S[N[H[b]]]) < 0 ? 1 : 0;
}
//挿入関数
void hin(int a) {
  int i = C++;
  for (N[H[0] = R] = a; hyouka(0, i / 2); i /= 2)
    H[i] = H[i / 2];
  H[i] = R++;
}
//取り出す関数
int hout() {
  int rt = H[1], i, j = 2, k = H[--C];
  for (i = 1; hyouka(i, C); i = j)
    H[i] = H[j = i * 2 + 1 - hyouka(i * 2, i * 2 + 1)];
  H[j / 2] = k;
  return rt;
}
int main() {
  int n, i, m = 0, d[200010], b[200010] = {1};
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", S[i]);
    hin(i);
  }
  for (i = 0; i < n; i++)
    d[i] = N[hout()];
  // for(i=0;i<n;i++)printf("!!%s\n",S[d[i]]);
  for (i = 1; i < n; i++) {
    if (strcmp(S[d[i]], S[d[i - 1]]) == 0)
      b[i] = b[i - 1] + 1;
    else
      b[i] = 1;
    if (m < b[i])
      m = b[i];
  }
  // for(i=0;i<n;i++)printf("%d\n",b[i]);
  for (i = 0; i < n; i++) {
    if (b[i] == m)
      printf("%s\n", S[d[i]]);
  }
  return 0;
}
