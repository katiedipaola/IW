#include <stdio.h>
int main(void) {
  int n, d = 0, i, j;
  char s[101], t[51];
  scanf("%d", &n);
  scanf("%s", s);

  for (i = 0; i < n / 2; i++) {
    t[i] = s[i];
  }
  for (j = 0; j < n / 2; j++) {
    if (s[i++] != t[j]) {
      d = 1;
      break;
    }
  }
  if (d == 1 || n % 2 == 1) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
}