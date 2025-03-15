#include <stdio.h>

int main(void) {
  // Your code here!
  long long int a[200001];
  long long int b[200001];
  int n, m, k;

  a[0] = 0;
  b[0] = 0;

  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld", &b[i]);
    b[i] += b[i - 1];
  }

  int max = 0;
  int jbest = m;

  for (int i = 0; i <= n; i++) {
    for (int j = m; m >= 0; j--) {
      if (a[i] + b[j] <= k) {
        if (i + j > max) {
          max = i + j;
        }
        break;
      }
    }
  }

  /*
  for(int i=0;i<n;i++){
      printf("%lld ",a[i]);
  }
   for(int i=0;i<m;i++){
      printf("%lld ",b[i]);
  }*/

  printf("%d", max);
}