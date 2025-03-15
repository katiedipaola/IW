#include <stdio.h>
#include <stdlib.h>

long long int compare(long long int x, long long int y) { return y - x; }

int main() {
  int i;
  int N;
  long long int result;
  long long int *arr;
  scanf("%d\n", &N);
  arr = (long long int *)malloc(sizeof(long long int) * N);
  for (i = 0; i < N; i++) {
    scanf("%lld", &(arr[i]));
  }
  qsort(arr, N, sizeof(long long int), compare);
  result = 0;
  for (i = 0; i < N - 1; i++) {
    result += arr[(i + 1) / 2];
  }
  printf("%lld\n", result);
  free(arr);
  return 0;
}
