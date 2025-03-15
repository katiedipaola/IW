#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define */
#define Yes(X) puts(X ? "Yes" : "No")
#define YES(X) puts(X ? "YES" : "NO")
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max3(a, b, c) ((max((a), (b)) > (c)) ? max((a), (b)) : (c))
#define min3(a, b, c) ((min((a), (b)) < (c)) ? min((a), (b)) : (c))

/* const */
const int MOD = (int)1e9 + 7;

/* alias */
typedef long long ll;
typedef unsigned u;

/* function */
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int cmp2(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int gcd(int a, int b) {
  if (b != 0)
    return gcd(b, a % b);
  return a;
}
ll Lgcd(ll a, ll b) {
  if (b != 0)
    return Lgcd(b, a % b);
  return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
ll Llcm(ll a, ll b) { return a / Lgcd(a, b) * b; }

/* main */
int n, m, ans = 0;
int a[60], b[60], visited[60], graph[60][60] = {};

void dfs(int v) {
  visited[v] = 1;
  REP(i, n) if (graph[v][i] == 1 && visited[i] == 0) dfs(i);
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    scanf("%d%d", &a[i], &b[i]);
    a[i]--;
    b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
  }
  REP(i, m) {
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 0;
    REP(j, n) visited[j] = 0;
    dfs(0);
    REP(j, n) if (visited[j] == 0) {
      ans++;
      break;
    }
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
  }
  printf("%d", ans);
  return 0;
}