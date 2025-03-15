#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
int bubbleSort(int A[], int n) {
    int i, j, t, s;
    int cnt = 0; // 反転数
    for(i=0;i<n-1;i++) {
        for(j=n-1,s=i+1;j>=s;j--) {
            if(A[j] < A[j-1]) {
                t = A[j];
                A[j] = A[j-1];
                A[j-1] = A[j];
                cnt++;
            }
        }
    }

    return cnt;
}
*/

long long int A[200005];
long long int merge_count(int l, int r) {
  long long int count = 0;
  int i, j, k;
  int n = r - l;
  if (n > 1) {
    long long int b[n + 5];
    int m = l + n / 2;
    count += merge_count(l, m);
    count += merge_count(m, r);
    memcpy((void *)b, (void *)&A[l], sizeof(b));
    for (i = l, j = 0, k = n / 2; i < r; ++i) {
      if (j == n / 2) {
        A[i] = b[k++];
      } else if (k == n) {
        A[i] = b[j++];
      } else if (b[j] <= b[k]) {
        A[i] = b[j++];
      } else {
        A[i] = b[k++];
        count += n / 2 - j;
      }
    }
  }
  return count;
}

long long int bubble_sort(int n) { return merge_count(0, n); }

int main(void) {
  int i, n;
  scanf("%d\n", &n);

  for (i = 0; i < n; i++) {
    scanf("%lld", &A[i]);
  }

  printf("%lld\n", bubble_sort(n));

  return 0;
}