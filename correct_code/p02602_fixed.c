#include <stdio.h>

int main() {
  int n, k;
  static int a[200002] = {0};
  static unsigned long long int r[200002] = {0};

  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  r[k] = 1;
  for (int i = 1; i <= k; i++) {
    r[k] += a[k - i];
  }

  for (int i = k + 1; i <= n; i++) {
    r[i] = r[i - 1] - a[i - k - 1] + a[i - 1];

    if (r[i] > r[i - 1]) {
      puts("Yes");
    } else {
      puts("No");
    }
  }

  return 0;
}
