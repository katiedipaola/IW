#include "math.h"
#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[]) {
  char *S;
  scanf("%s", S);
  int N = strlen(S);

  int i;
  int w = 0;
  long long int ans = 0;
  for (i = 0; i < N; i++) {
    if (S[i] == 'W') {
      ans = ans + i - w;
      w++;
    }
  }
  if (w == N || w == 0) {
    ans = 0;
  }
  printf("%lld", ans);
  return 0;
}
