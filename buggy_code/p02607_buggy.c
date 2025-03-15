#include <stdio.h>

int main(void) {
  int N;
  int a[200];
  int c = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", &a[i]);

  for (int i = 1; i < N; i = i + 2) {
    if (a[i] % 2 == 1)
      c++;
  }

  printf("%d\n", c);

  return 0;
}