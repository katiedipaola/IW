#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int i, j, N;
  char R[220], S[110], T[110], U[110], V[110];
  scanf("%d", &N);
  scanf("%s", &S);
  scanf("%s", &T);
  //	printf("%s %s\n", S, T);

  memmove(R, S, N);
  for (i = 0; i < N; i++) {
    memset(U, 0, 110);
    memset(V, 0, 110);
    memmove(U, R + i, N - i);
    memmove(V, T, N - i);
    //		printf("%s %s\n", U, V);
    if (!strcmp(U, V)) {
      memmove(R + N, T + N - i, i);
      break;
    }
  }
  if (i == N)
    memmove(R + N, T, N);
  R[N + i] = '\0';

  //	printf("%s\n", R);
  printf("%d\n", strlen(R));

  return 0;
}