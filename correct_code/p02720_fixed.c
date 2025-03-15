#include <stdio.h>

#define N 100003
#define INF 1 << 29

int enqueue(long *queue, long data, int *head, int *tail) {
  if (*head % N != (*tail + 1) % N) {
    queue[(*tail)++ % N] = data;
    return *tail - *head;
  } else {
    return INF;
  }
}

long dequeue(long *queue, int *head, int *tail) {
  if (*head != *tail) {
    return queue[(*head)++ % N];
  } else {
    return INF;
  }
}

void initQueue(long *queue, int *head, int *tail) {
  for (long i = 1; i <= 9; i++)
    enqueue(queue, i, head, tail);
}

int main(void) {
  long queue[N], x;
  int k, head = 0, tail = 0;

  scanf("%d", &k);

  initQueue(queue, &head, &tail);
  for (int i = 0; i < k; i++) {
    if (k <= tail - head) {
      for (int j = i; j < k - 1; j++)
        dequeue(queue, &head, &tail);
      printf("%ld", dequeue(queue, &head, &tail));
      return 0;
    }
    if ((x = dequeue(queue, &head, &tail)) == INF) {
      return 1;
    } else {
      for (int j = -1; j <= 1; j++) {
        int d = x % 10 + j;
        if (d < 0 || d > 9)
          continue;
        if (enqueue(queue, 10 * x + d, &head, &tail) == INF)
          return 1;
      }
    }
  }

  return 0;
}