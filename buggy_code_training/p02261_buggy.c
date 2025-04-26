#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int number;
  char sign;
} CARD;

void bubbleSort(CARD *, int);
void SelectionSort(CARD *, int);
int isStable(CARD *, CARD *);
void swap(CARD *, CARD *);
void Print(CARD *, int);

int n, answer;
CARD *C1, *C2;

int main() {
  int i, a;

  scanf("%d", &n);
  C1 = malloc(n * sizeof(CARD));
  C2 = malloc(n * sizeof(CARD));

  for (i = 0; i < n; i++) {
    scanf(" %c%d", &C1[i].sign, &C1[i].number);
    C2[i] = C1[i];
  }

  bubbleSort(C1, n);

  SelectionSort(C2, n);

  Print(C1, n);
  if (answer == 0) {
    printf("Stable\n");
  } else
    printf("Not stable\n");

  Print(C2, n);

  answer = isStable(C1, C2);

  if (answer == 0) {
    printf("Not Stable\n");
  } else
    printf("stable\n");

  free(C1);
  free(C2);

  return 0;
}

void bubbleSort(CARD *x, int n) {
  int i, j, count = 0, minj;
  for (i = 0; i <= n - 1; i++) {
    for (j = n - 1; j >= i + 1; j--) {
      if (x[j].number < x[j - 1].number) {
        swap(&x[j], &x[j - 1]);
        /*swap=x[j];
        x[j]=x[j-1];
        x[j-1]=swap;*/
      }
    }
  }
}

void SelectionSort(CARD *y, int n) {
  int i, j, minj;
  for (i = 0; i <= n - 1; i++) {
    minj = i;
    for (j = i; j <= n - 1; j++) {
      if (y[j].number < y[minj].number) {
        minj = j;
        // swap(&y[i],&y[minj]);
      }
    }
    if (i != minj) {
      swap(&y[i], &y[minj]);
    }
  }
}

int isStable(CARD *in, CARD *out) {
  int i;
  for (i = 0; i < n; i++) {
    if (in[i].sign != out[i].sign) {
      return 0;
    }
  }
  return 1;
}

void Print(CARD *x, int n) {
  int i;

  for (i = 0; i < n - 1; i++) {
    printf("%c%d ", x[i].sign, x[i].number);
  }
  printf("%c%d\n", x[n - 1].sign, x[n - 1].number);
}

void swap(CARD *x, CARD *y) {
  CARD work;

  work = *x;
  *x = *y;
  *y = work;
}