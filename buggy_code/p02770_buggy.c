#include <stdio.h>

#define MAX_K 5000
#define MAX_Q 5000

int d[MAX_K];

void cnt_j(int d[], int k) {
  int n, x, m;
  int d_moded[MAX_K];
  int i, quo_k, rem_k;
  long long cnt_not_j = 0;
  long long max_a;

  scanf("%d %d %d", &n, &x, &m);

  max_a = x;
  quo_k = (n - 1) / k;
  rem_k = (n - 1) % k;
  for (i = 0; i < k; i++) {
    d_moded[i] = d[i] % m;
    if (d_moded[i] == 0) {
      cnt_not_j += quo_k + (i < rem_k);
    }
    max_a += d_moded[i] * (quo_k + (i < rem_k));
  }

  cnt_not_j += max_a / m - x / m;

  printf("%lld\n", n - 1 - cnt_not_j);
}

int main() {
  int k, q;
  int i;

  scanf("%d %d", &k, &q);
  for (i = 0; i < k; i++) {
    scanf("%d", d + i);
  }
  for (i = 0; i < q; i++) {
    cnt_j(d, k);
  }

  return 0;
}
