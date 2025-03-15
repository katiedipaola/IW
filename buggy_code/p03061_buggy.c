#include <stdio.h>
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) ((a) > (b) ? (b) : (a))

int gcd(int x, int y) {
  int ans = 0;
  int m = max(x, y);
  int n = min(x, y);
  while (n != 0) {
    int temp = n;
    n = m % n;
    m = temp;
  }
  ans = m;
  return ans;
}

int main() {
  int N;
  int A[100000] = {};
  int max = -1;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  int head[100000] = {};
  int back[100000] = {};
  head[0] = back[N - 1] = 0;

  for (int i = 0; i < N - 1; i++) {
    head[i + 1] = gcd(head[i], A[i]);
  }

  for (int i = N - 1; i > 0; i--) {
    back[i - 1] = gcd(back[i], A[i]);
  }

  for (int i = 0; i < N - 1; i++) {
    if (max < gcd(head[i], back[i])) {
      max = gcd(head[i], back[i]);
    }
  }

  printf("%d", max);

  return 0;
}