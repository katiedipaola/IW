#include <stdio.h>

int main(void) {

  int n[2];
  int i, a, j;

  for (i = 0; i < 3; i++) {
    scanf("%d", &n[i]);
  }

  a = n[0];

  for (i = 0; i <= 1; i++) {
    for (j = i + 1; j <= 2; j++) {
      if (n[j] > n[i]) {
        a = n[j];
        n[j] = n[i];
        n[i] = a;
      }
    }
  }

  printf("%d\n", n[1] + n[2]);

  return 0;
}
