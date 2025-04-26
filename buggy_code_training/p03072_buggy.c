#include <stdio.h>
int main(void) {
  int N, counter = 0, check = 0;

  scanf("%d", &N);
  int H[N], i, j = 0;
  for (i = 0; i < N; i++)
    scanf("%d", &H[i]);

  i = 0;
  while (i < N - 1) {
    while (j < i) {
      if (H[j] <= H[i])
        check++;
      j++;
    }
    if (check == i)
      counter++;
    check = 0;
    i++;
    j = 0;
  }
  printf("%d", counter);

  return 0;
}