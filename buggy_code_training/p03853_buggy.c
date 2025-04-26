#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define S_MAX 100
#define N_MAX 100000
#define M_MAX 200000
#define INF 10000000
#define MOD 1000000007
#define SMAP(a, b) ((a) != (b)) && ((a) ^= ((b) ^= ((a) ^= (b))))

typedef unsigned long long ull;
typedef signed long long dll;

int n, m;
int h, w;
int i, j, k;
ull a, b;

ull x[N_MAX];
char s[S_MAX + 1];

typedef struct {
  int in;
  int out;
} twoway;

void deb() { return; }

void solve() {
  ull result = 0;
  int p = 0;

  return;
}

int main(void) {
  char *t;
  bool x[26] = {0};
  scanf("%d%d", &h, &w);

  for (i = 0; i < h; i++) {
    scanf("%s", s);
    puts(s);
  }

  solve();
  return 0;
}
