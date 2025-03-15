#include <stdio.h>
#include <stdlib.h>
void countingSort(int k, int size, int A[], int B[]);
int findmax(int size, int A[]);
int main(int argc, char **argv) {
  int size;
  scanf("%d", &size);
  int arrayA[size];

  for (int i = 1; i < size + 1; i++) {
    scanf("%d", &arrayA[i]);
  }

  int k = findmax(size, arrayA);
  int arrayB[size + 1];
  countingSort(k, size, arrayA, arrayB);
  for (int i = 1; i < size + 1; i++) {
    if (i < size)
      printf("%d ", arrayB[i]);
    if (i == size)
      printf("%d\n", arrayB[i]);
  }
  return (EXIT_SUCCESS);
}
int findmax(int size, int A[]) {
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  return max;
}
void countingSort(int k, int size, int A[], int B[]) {
  int C[k + 1];
  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }
  for (int j = 1; j <= size; j++) {
    C[A[j]] = C[A[j]] + 1;
  }
  for (int i = 1; i <= k; i++) {
    C[i] = C[i] + C[i - 1];
  }
  for (int j = size; j >= 1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
}
