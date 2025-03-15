#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N = 0;
  int *a = NULL;

  scanf("%d", &N);

  a = calloc(N, sizeof(int));

  int i;
  for (i = 0; i < N; i++) {
    scanf("%d", &(a[i]));
  }

  int friend = 0;

  for (i = 0; i < N; i++) {
    // printf("i = %d; a[i] = %d; a[a[i]] = %d;\n", i, a[i], a[a[i]]);
    if (a[a[i] - 1] == i + 1) {
      friend ++;
    }
  }

  friend /= 2;

  printf("%d\n", friend);

  return EXIT_SUCCESS;
}
