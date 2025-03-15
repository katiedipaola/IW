#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long long *data;
  int size;
} max_heap;

void push(long long x, max_heap *h) {
  int i = h->size;
  h->data[(h->size)++] = x;
  while (1) {
    if (i == 0)
      break;
    else if (h->data[i] > h->data[(i - 1) / 2]) {
      h->data[i] += h->data[(i - 1) / 2];
      h->data[(i - 1) / 2] = h->data[i] - h->data[(i - 1) / 2];
      h->data[i] -= h->data[(i - 1) / 2];
      i = (i - 1) / 2;
    } else
      break;
  }
}

long long pop(max_heap *h) {
  int i = 0, j;
  long long output = h->data[0];
  h->data[0] = h->data[--(h->size)];
  while (1) {
    if (i * 2 + 1 >= h->size)
      break;
    else if (i * 2 + 2 >= h->size)
      j = i * 2 + 1;
    else if (h->data[i * 2 + 1] > h->data[i * 2 + 2])
      j = i * 2 + 1;
    else
      j = i * 2 + 2;
    if (h->data[j] > h->data[i]) {
      h->data[i] += h->data[j];
      h->data[j] = h->data[i] - h->data[j];
      h->data[i] -= h->data[j];
      i = j;
    } else
      break;
  }
  return output;
}

int main() {
  int i, N, M;
  long long A[100001];
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; i++)
    scanf("%lld", &(A[i]));

  long long sum = 0, tmp;
  max_heap h;
  h.data = (long long *)malloc(sizeof(long long) * (N + 1));
  h.size = 0;
  for (i = 1; i <= N; i++)
    push(A[i], &h);
  for (i = 1; i <= M; i++) {
    tmp = pop(&h);
    tmp /= 2;
    push(tmp, &h);
  }

  for (i = 1; i <= N; i++)
    sum += pop(&h);
  printf("%lld\n", sum);
  fflush(stdout);
  return 0;
}