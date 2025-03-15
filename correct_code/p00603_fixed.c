#include <stdio.h>

static const int MAX_CARD_SIZE = 52;
static const int SENTINEL = 1000;

int main(void) {
  int i, j, k, t, n, r, c;
  int p_a, p_b, p_c, deck_A[MAX_CARD_SIZE / 2], deck_B[MAX_CARD_SIZE / 2],
      deck_C[MAX_CARD_SIZE];

  while (EOF != scanf(" %d %d", &n, &r)) {
    for (i = 0; i < n; i++) {
      deck_C[i] = i;
    }

    for (i = 0; i < r; i++) {
      scanf(" %d", &c);

      t = n / 2;
      for (j = 0; j < t; j++) {
        deck_B[j] = deck_C[j];
      }
      deck_B[j] = SENTINEL;

      for (j = t; j < n; j++) {
        deck_A[j - t] = deck_C[j];
      }
      deck_A[j - t] = SENTINEL;

      /*
       * for (j = 0; deck_A[j] != SENTINEL; j++) {
       *     printf("%d ", deck_A[j]);
       * }
       * printf("\n");
       * for (j = 0; deck_B[j] != SENTINEL; j++) {
       *     printf("%d ", deck_B[j]);
       * }
       * printf("\n");
       */

      // merge
      p_a = p_b = p_c = 0;
      while (deck_A[p_a] != SENTINEL || deck_B[p_b] != SENTINEL) {
        for (k = 0; k < c; k++) {
          if (deck_A[p_a] == SENTINEL) {
            break;
          }
          deck_C[p_c++] = deck_A[p_a++];
        }

        for (k = 0; k < c; k++) {
          if (deck_B[p_b] == SENTINEL) {
            break;
          }
          deck_C[p_c++] = deck_B[p_b++];
        }
      }

      /*
       * for (j = 0; j < n; j++) {
       *     printf("%d ", deck_C[j]);
       * }
       * printf("\n");
       */
    }
    printf("%d\n", deck_C[n - 1]);
  }

  return 0;
}