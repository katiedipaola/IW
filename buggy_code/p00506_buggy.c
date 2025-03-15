#include <stdio.h>
int mintwo(int kouyaku1, int kouyaku2);
int minthree(int kouyaku1, int kouyaku2, int kouyaku3);
void kouyakutwo();
void kouyakuthree();

int main(void) {
  int n = 0;

  scanf("%d", &n);
  if (n == 2) {
    kouyakutwo();
  } else {
    kouyakuthree();
  }
}

void kouyakutwo() {
  int kouyaku1 = 0, kouyaku2 = 0, i = 1;
  int minvalue;
  scanf("%d %d", &kouyaku1, &kouyaku2); //数値を入力

  minvalue = mintwo(kouyaku1, kouyaku2);

  while (i <= minvalue) {
    if (kouyaku1 % i == 0 && kouyaku2 % i == 0) {
      printf("%d ", i);
    }
    i = i + 1;
  }
}

void kouyakuthree() {
  int kouyaku1 = 0, kouyaku2 = 0, kouyaku3 = 0;
  int i = 1;
  int minvalue;

  scanf("%d %d %d", &kouyaku1, &kouyaku2, &kouyaku3);

  minvalue = minthree(kouyaku1, kouyaku2, kouyaku3);

  while (i <= minvalue) {
    if (kouyaku1 % i == 0 && kouyaku2 % i == 0 && kouyaku3 % i == 0) {
      printf("%d \n", i);
    }
    i = i + 1;
  }
}

int mintwo(int kouyaku1, int kouyaku2) {
  int minvalu;

  if (kouyaku1 < kouyaku2) {
    minvalu = kouyaku1;
  } else {
    minvalu = kouyaku2;
  }

  return minvalu;
}

int minthree(int kouyaku1, int kouyaku2, int kouyaku3) {
  int minvalu;
  minvalu = kouyaku1;
  if (minvalu > kouyaku2) {
    minvalu = kouyaku2;
  }
  if (minvalu > kouyaku3) {
    minvalu = kouyaku3;
  }

  return minvalu;
}
