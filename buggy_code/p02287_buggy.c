#include <stdio.h>

#define HEAP_SIZE 250

int main() {
  int heap[HEAP_SIZE + 1];
  int i, n;

  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &heap[i]);
  }

  for (i = 1; i <= n; i++) {
    printf("node %d: key = %d, ", i, heap[i]);
    if (0 < (i / 2)) {
      printf("parent kye = %d, ", heap[i / 2]);
    }
    if ((2 * i) <= n) {
      printf("left key = %d, ", heap[2 * i]);
    }
    if ((2 * i + 1) <= n) {
      printf("right key = %d, ", heap[2 * i + 1]);
    }
    printf("\n");
  }

  return (0);
}