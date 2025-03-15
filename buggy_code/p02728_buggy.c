#include <stdio.h>
int ta[200010], nt[400010], to[400010], cc[400010];
long long u[200010], ANS[200020], ans[200020];
int mbk(long long a, int n, int m) {
  return n ? (mbk((a * a) % m, n / 2, m) * (n % 2 ? a : 1)) % m : 1;
}
int inv(int a, int m) { return mbk((long long)a, m - 2, m); }
long long pp[200010], M = 1e9 + 7;
void fc(int s, int t) { ans[s] = ans[s] * ans[t] % M; }
void ic(int s, int t) { ans[s] = ans[s] * inv(ans[t], M); }
void fp(int s) { ans[s] = ans[s] * inv(cc[s], M) % M; }
void ip(int s) { ans[s] = ans[s] * cc[s] % M; }
void f(int s) { // printf("!%d\n",s);
  long long i;
  u[s] = 1;
  for (i = ta[s]; i + 1; i = nt[i]) {
    if (u[to[i]])
      continue;
    f(to[i]);
    fc(s, to[i]);
    cc[s] += cc[to[i]];
  }
  fp(s);
}

void h(int s, int t) {
  ip(s);
  ic(s, t);
  ip(t);
  cc[s] -= cc[t];
  cc[t] += cc[s];
  fp(s);
  fc(t, s);
  fp(t);
}
void g(int s) { // printf("!!%d %d\n",s,cc[s]);
  int i;
  u[s] = 2;
  ANS[s] = ans[s];
  for (i = ta[s]; i + 1; i = nt[i]) {
    if (u[to[i]] == 2)
      continue;
    // printf("%d %d %d %d %lld
    // %lld\n",s,to[i],cc[s],cc[to[i]],ans[s],ans[to[i]]);
    h(s, to[i]);
    // printf("%d %d %d %d %lld
    // %lld\n",s,to[i],cc[s],cc[to[i]],ans[s],ans[to[i]]);
    g(to[i]);
    h(to[i], s);
  }
}
int main() {
  int n, a, b, i;
  scanf("%d", &n);
  for (i = 0; i <= n; i++)
    ta[i] = -1;
  pp[0] = 1;
  for (i = 1; i <= n; i++)
    pp[i] = (pp[i - 1] * i) % M;
  // for(i=0;i<=n;i++)ip[i]=inv(i,M);
  for (i = 1; i <= n; i++)
    ans[i] = cc[i] = 1;
  for (i = 0; i < n - 1; i++) {
    scanf("%d %d", &a, &b);
    nt[i] = ta[to[i + n - 1] = a];
    nt[i + n - 1] = ta[to[i] = b];
    ta[b] = i + n - 1;
    ta[a] = i;
  }
  f(1);
  // for(i=0;i<=10;i++)printf("%lld\n",pp[i]);printf("\n");
  // for(i=0;i<=n;i++)printf("%d\n",cc[i]);
  // printf("%d\n",f(1));
  // for(i=0;i<=n;i++)printf("%d\n",cc[i]);
  // for(i=1;i<=n;i++)printf("%3d ",i);printf("\n");
  // for(i=1;i<=n;i++)printf("%3lld ",ans[i]);printf("\n");
  // for(i=1;i<=n;i++)printf("%3d ",cc[i]);printf("\n");
  g(1);
  for (i = 1; i <= n; i++)
    printf("%lld\n", ANS[i] * pp[n] % M);
  return 0;
}
