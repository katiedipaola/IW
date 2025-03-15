#include <stdio.h>
#include <string.h>

void addcard(char[], char[], char[], int[], int, int, int, int *);

int main(void) {
  char cards[10 * 6000];
  char nowcard[10];
  char cardkouho[3 * 10];
  int cardmaisuu;
  int sentakumaisuu;
  int cardnokori[10];
  int i;
  int result;
  while (1) {
    scanf("%d", &cardmaisuu);
    scanf("%d", &sentakumaisuu);
    if (cardmaisuu == 0 && sentakumaisuu == 0)
      break;
    for (i = 0; i < cardmaisuu; i++) {
      scanf("%s", &cardkouho[3 * i]);
    }
    for (i = 0; i < cardmaisuu; i++) {
      cardnokori[i] = 1;
    }
    for (i = 0; i < 60000; i++) {
      cards[i] = 0;
    }
    for (i = 0; i < 10; i++) {
      nowcard[i] = 0;
    }
    result = 0;
    addcard(cards, nowcard, cardkouho, cardnokori, 1, sentakumaisuu, cardmaisuu,
            &result);
    printf("%d\n", result);
  }
  return 0;
}

void addcard(char cards[], char nowcard[], char cardkouho[], int cardnokori[],
             int nowmaime, int max, int cardkouhomaisuu, int *cardmaisuu) {
  int i;
  int ii;
  int ng;
  int cardlen;
  for (i = 0; i < cardkouhomaisuu; i++) {
    if (cardnokori[i] == 1) {
      cardnokori[i] = 0;
      cardlen = strlen(nowcard);
      strcat(nowcard, &cardkouho[3 * i]);
      if (nowmaime < max) {
        addcard(cards, nowcard, cardkouho, cardnokori, nowmaime + 1, max,
                cardkouhomaisuu, cardmaisuu);
      } else {
        ng = 0;
        for (ii = 0; ii < (*cardmaisuu); ii++) {
          if (strcmp(nowcard, &cards[10 * ii]) == 0) {
            ng = 1;
            break;
          }
        }
        if (ng == 0) {
          strcpy(&cards[10 * (*cardmaisuu)], nowcard);
          (*cardmaisuu)++;
        }
      }
      nowcard[cardlen] = 0;
      cardnokori[i] = 1;
    }
  }
}