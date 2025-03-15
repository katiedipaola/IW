#include <stdio.h>

int main(void) {

  int n[3];
  int i, a, j;

  for (i = 0; i <= 2; i++) {
    scanf("%d", &n[i]);
  }

  a = n[1];

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
