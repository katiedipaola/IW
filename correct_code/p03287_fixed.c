#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int inorinn(const void *x, const void *y) {
  int64_t a = *(const int64_t *)x, b = *(const int64_t *)y;
  return a < b ? -1 : a > b;
}

int32_t N;
int64_t M;
int64_t A[114514];

int64_t mizuhasu[114514];

int main(void) {
  int32_t i;
  int64_t mikakosi = 0;
  int32_t parunyasu = 0;
  if (scanf("%" SCNd32 "%" SCNd64, &N, &M) != 2)
    return 1;
  for (i = 0; i < N; i++) {
    if (scanf("%" SCNd64, &A[i]) != 1)
      return 1;
  }
  for (i = 1; i <= N; i++) {
    mizuhasu[i] = (mizuhasu[i - 1] + A[i - 1]) % M;
  }
  qsort(mizuhasu, N + 1, sizeof(*mizuhasu), inorinn);
  for (i = 1; i <= N + 1; i++) {
    if (i > N || mizuhasu[i] != mizuhasu[parunyasu]) {
      int64_t sumipe = i - parunyasu;
      mikakosi += sumipe * (sumipe - 1) / 2;
      parunyasu = i;
    }
  }
  printf("%" PRId64 "\n", mikakosi);
  return 0;
}
