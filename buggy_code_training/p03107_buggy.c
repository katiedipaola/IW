#include <stdio.h>
#include <string.h>

static char S[100000];
static int N;
int main(void) {
  scanf("%s", S);
  N = strlen(S);

  int Zero = 0;
  int One = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '0') {
      Zero++;
    } else {
      One++;
    }
  }

  int Min = (Zero < One) ? Zero : One;
  printf("%d\n", Min);
  return 0;
}
