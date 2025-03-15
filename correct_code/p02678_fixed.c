#include <stdio.h>
#include <stdlib.h>
#define size 100001
int *pass[size];
int deep[size];
int pass_s[size];
int qu[size];
int N, M;
void set() {
  int a, b;
  for (int j = 0; j < N; j++) {
    deep[j] = -1;
    pass_s[j] = 0;
  }
  deep[0] = 0;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a, &b);
    a--;
    b--;
    pass[a] = (int *)realloc(pass[a], sizeof(int) * (pass_s[a] + 1));
    pass[a][pass_s[a]] = b;
    pass_s[a]++;
    pass[b] = (int *)realloc(pass[b], sizeof(int) * (pass_s[b] + 1));
    pass[b][pass_s[b]] = a;
    pass_s[b]++;
  }
}
void sys() {
  int point = 0, tar = 0, nm = 0;
  while (1) {
    for (int i = 0; i < pass_s[tar]; i++) {
      if (deep[pass[tar][i]] != -1)
        continue;
      deep[pass[tar][i]] =
          tar +
          1; //指向房间号的deep为当前房间号+1即为题设房间号//deep[pass[tar][i]]=deep[tar]+1;这是计算深度用的
      qu[nm] = pass[tar][i];
      nm++;
    }
    if (nm == point)
      break;
    tar = qu[point];
    point++;
  }
}
int main() {
  scanf("%d %d", &N, &M);
  set();
  sys();
  printf("Yes\n");
  for (int i = 1; i < N; i++) {
    printf("%d\n", deep[i]);
  }
  return 0;
}