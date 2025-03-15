#include <stdio.h>

#define MAX 50000000

void maxHeapify(int *, int);
void swap(int *, int *);

int H;

int main() {
  int i, A[MAX];

  scanf("%d", &H);

  for (i = 1; i <= H; i++) {

    scanf("%d", &A[i]);
  }

  for (i = H / 2; i > 0; i--) {
    maxHeapify(A, i);
  }

  for (i = 1; i <= H; i++) {

    printf(" %d", A[i]);
  }
  printf("\n");

  return 0;
}

void maxHeapify(int *A, int i) {
  int l, r, largest;
  l = 2 * i;
  r = 2 * i + 1;
  largest = i;

  if (A[largest] < A[l] && l <= H)
    largest = l;
  if (A[largest] < A[r] && r <= H)
    largest = r;

  if (largest != i) {
    swap(&A[i], &A[largest]);
    maxHeapify(A, largest);
  }
}

void swap(int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}