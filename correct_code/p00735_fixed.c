#include <stdio.h>

#include <math.h>

#define MAX 300000

int main() {

  int i, j;

  int n;

  int board[MAX + 1];

  for (i = 0; i < MAX; i++) {

    board[i] = (i % 7 == 1 || i % 7 == 6);
  }

  board[1] = 0;

  j = 6;

  while (j < MAX) {

    for (i = 2 * j; i < MAX; i += j)
      board[i] = 0;

    j++;

    while (!board[j]) {

      if (j == MAX - 1)
        break;

      j++;
    }

    if (j == MAX - 1)
      j++;
  }

  while (scanf("%d", &n), n != 1) {

    printf("%d:", n);

    for (i = 0; i <= n; i++) {

      if (board[i]) {

        if (n % i == 0)
          printf(" %d", i);
      }
    }

    puts("");
  }

  return 0;
}