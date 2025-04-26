#include <stdio.h>
#include <stdlib.h>

#define MAX 2000003

int A[MAX];
int heap_size = 0;

int Parent(int i) { return i / 2; }
int Left(int i) { return 2 * i; }
int Right(int i) { return 2 * i + 1; }

void maxHeapify(int i) {
  int l, r, largest;
  int temp;

  l = Left(i);
  r = Right(i);

  if ((l <= heap_size) && (A[l] > A[i])) {
    largest = l;
  } else {
    largest = i;
  }

  if ((r <= heap_size) && (A[r] > A[largest])) {
    largest = r;
  }

  if (largest != i) {
    temp = A[i];
    A[i] = A[largest];
    A[largest] = temp;

    maxHeapify(largest);
  }
}

int heapExtractMax(void) {
  int max, j;
  if (heap_size < 1) {
    return -20;
  }
  max = A[1];
  A[1] = A[heap_size];
  heap_size = heap_size - 1;

  maxHeapify(1);

  return max;
}

void heapIncreaseKey(int i, int key) {
  int temp;
  if (key < A[i]) {
    printf("error\n");
    exit(1);
  }

  A[i] = key;

  while ((i > 1) && (A[Parent(i)] < A[i])) {
    temp = A[i];
    A[i] = A[Parent(i)];
    A[Parent(i)] = temp;

    i = Parent(i);
  }
}

void maxHeapInsert(int key) {
  heap_size = heap_size + 1;
  A[heap_size] = -1000000000;
  heapIncreaseKey(heap_size, key);
}

int main(void) {
  int i = 1, j = 0, max, a;
  char com[20];

  while (1) {
    scanf("%s", com);
    if (com[0] == 'i') {
      scanf("%d", &a);
      maxHeapInsert(a);

      heap_size++;
    }

    else if (com[0] == 'e' && com[1] == 'x') {
      max = heapExtractMax();
      if (max == -20) {
        exit(0);
      }
      printf("%d\n", max);
    } else {
      break;
    }
  }

  return 0;
}