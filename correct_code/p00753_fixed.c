#include <stdio.h>

int makelist(int *list, int kazu) {
  int i, j;
  for (i = 0; i < kazu; i++) {
    list[i] = 1;
  }
  list[0] = 0;
  list[1] = 0;
  for (i = 2; i < kazu; i++) {
    if (list[i]) {
      for (j = 2 * i; j < kazu; j += i) {
        list[j] = 0;
      }
    }
  }
  return 0;
}

int main() {
  int list[300000];
  int n, ans;
  int i;
  makelist(list, 300000);
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    ans = 0;
    for (i = n + 1; i <= 2 * n; i++) {
      if (list[i] == 1)
        ans++;
    }

    printf("%d\n", ans);
  }

  return 0;
}