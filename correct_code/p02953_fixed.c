#include <stdio.h>
int main(void) {
  int n;
  int h[100000];
  int i;
  int flag;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
  }
  i = n;
  flag = 1;
  while (i > 1 && flag != 0) {
    if (h[i - 1] - h[i] >= 2) {
      flag = 0;
    } else if (h[i - 1] - h[i] == 1) {
      h[i - 1] = h[i - 1] - 1;
    }
    i--;
  }

  if (flag == 0 && n != 1) {
    printf("No");
  } else {
    printf("Yes");
  }

  return 0;
}