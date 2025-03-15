#include <stdio.h>

#define A 1000010

int mp[A];
int nxt[A];
int prs[A];
char ex[A];

int gcd(int x, int y) {
  while (y) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(void) {
  int k = 0;
  for (int i = 2; i < A; ++i) {
    if (!mp[i]) {
      mp[i] = i;
      prs[k++] = i;
    }
    int m = mp[i];
    int r = nxt[i];
    for (int j = 0; j < k; ++j) {
      int t = prs[j];
      int u = i * t;
      if (t > m || u >= A) {
        break;
      }
      mp[u] = t;
      nxt[u] = t == m ? r : i;
    }
  }

  int n;
  scanf("%d", &n);
  int d = 0;
  int pc = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    d = gcd(x, d);
    if (pc) {
      while (x > 1) {
        pc &= !ex[mp[x]];
        ex[mp[x]] = 1;
        x = nxt[x];
      }
    }
  }
  if (pc) {
    puts("pairwise coprime");
  } else if (d == 1) {
    puts("setwise coprime");
  } else {
    puts("not coprime");
  }
}
