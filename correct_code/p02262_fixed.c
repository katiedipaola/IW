#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int, int[], int, int);
int shellSort(int, int[]);
void printArray(int[], int);
int main(int argc, char **argv) {
  int size;
  scanf("%d\n", &size);
  int array[size];
  for (int i = 0; i < size; i++)
    scanf("%d", &array[i]);

  int count = shellSort(size, array);
  printf("%d\n", count);
  printArray(array, size);

  return (EXIT_SUCCESS);
}

int insertion_sort(int size, int array[size], int gap, int count) {
  int temp, j;
  for (int i = gap; i < size; i++) {
    temp = array[i];
    j = i - gap;
    while (j >= 0 && array[j] > temp) {
      array[j + gap] = array[j];
      j -= gap;
      if (size != 1)
        count++;
    }
    array[j + gap] = temp;
  }
  return count;
}

int shellSort(int size, int array[size]) {
  int count = 0;
  int m;
  for (int i = 1; (pow(3, i) - 1) / 2 <= size; i++)
    m = i;
  int gap[m]; // Pratt 1971 Gap sequence
  for (int i = m; i > 0; i--)
    gap[i - 1] = (pow(3, i) - 1) / 2;
  printf("%d\n", m);
  for (int i = m - 1; i >= 0; i--) {
    if (size >= gap[i] || gap[i] == 1) {
      count = insertion_sort(size, array, gap[i], count);
      if (i != 0)
        printf("%d ", gap[i]);
      else
        printf("%d\n", gap[i]);
    }
  }
  return count;
}

void printArray(int array[], int count) {
  for (int i = 0; i < count; i++) {
    printf("%d\n", array[i]);
  }
}
