#include <stdio.h>
#define MAX 1000000007
int main(void) {
  // Your code here!
  long int N, K;
  long int A[40002];
  scanf("%ld %ld\n", &N, &K);
  long int i, j, min;
  min = 2001;

  for (i = 1; N >= i; i++) {
    scanf("%ld", &A[i]);
    A[i + N] = A[i];
    if (min > A[i])
      min = A[i];
  }
  long int count = 0;
  long int ct, tmp;
  for (i = 1; N >= i; i++) {
    for (j = i + 1; N + i >= j; j++) {
      ct = 0;
      // printf("%d:%d %d\n",j,A[i],A[j]);
      if (A[i] > A[j]) {
        tmp = j;
        // ct = 0;
        /*while(N*K+1>=tmp){
            tmp += N;
            ct++;
        }*/
        ct = (N * K - tmp) / N + 1;
        // printf("ct:%d\n",ct);
        count += ct * (1 + ct) / 2;
        if (count >= MAX)
          count = count % MAX;
      }
    }
  }

  printf("%ld", count);
  return 0;
}
