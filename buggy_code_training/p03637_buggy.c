#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int kisuu = 0;
  int ni = 0;
  int yon = 0;
  for (int i = 0; i < n; i++) {
    if (i % 4 == 0) {
      yon++;
    } else if (i % 2 == 0) {
      ni++;
    } else {
      kisuu++;
    }
  }
  int answer = 1;
  if (n % 2 != 0 && (n - ni + 1) / 2 < kisuu) {
    answer = 0;
  }
  if (n % 2 == 0 && (n - ni) / 2 < kisuu) {
    answer = 0;
  }

  if (answer == 1) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}