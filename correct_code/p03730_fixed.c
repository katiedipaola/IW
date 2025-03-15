#include <stdio.h>
#include <string.h>

char a[] = "0123456789";
int main() {
  int a, b, c;
  int x = 0;
  int i;
  int k = 0;
  scanf("%d%d%d", &a, &b, &c);
  for (i = 0; i < 1000; i++) {
    x = i * a;
    if (x % b == c) {

      k++;
    }
  }
  if (k > 0) {

    printf("YES\n");

  } else {
    printf("NO\n");
  }

  return 0;
}