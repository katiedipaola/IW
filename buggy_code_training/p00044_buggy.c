#include <stdio.h>
#define MAX 50001
int n;
int p[MAX];
int prime[1000];
int main() {
  int i, j, count = 0;

  for (i = 0; i < MAX; i++) {
    p[i] = 1;
  }
  for (i = 2; i * i < MAX; i++) {
    if (p[i] == 1) {
      for (j = i + i; j < MAX; j = j + i) {
        p[j] = 0;
      }
    }
  }
  for (i = 2; i < MAX; i++) {
    if (p[i] == 1) {
      prime[count] = i;
      count++;
    }
  }
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < count; i++) {
      if (n == prime[i]) {
        printf("%d %d\n", prime[i - 1], prime[i + 1]);
        break;
      }
      if (n < prime[i]) {
        printf("%d %d\n", prime[i - 1], prime[i]);
        break;
      }
    }
  }
  return 0;
}